#include "MatrixProblemClientHandler.h"
#include <sys/socket.h>
#include <unistd.h>
#include <vector>
#include "FileCacheManager.h"
#include "Point.h"
#include "State.h"

using namespace std;

vector<double> splitToDoubleByChar(string str, char c){
    vector<double> vec;
    size_t strLength = str.length();
    string num = "";
    for(size_t i = 0; i < strLength; i++){
        if(str[i] != c){
            num += str[i];
        } else{
            string::size_type sz;
            vec.push_back(stod(num, &sz));
            num = "";
        }
    }
    return vec;
}

vector<State<Point>> convertLineToMatrixRow(vector<double> costsVec, int lineNum){
    vector<State<Point>> vec;
    size_t vecSize = costsVec.size();
    for(size_t i = 0; i < vecSize; i++){
        Point p(lineNum, i);
        State<Point> s(p);
        s.setCost(costsVec.at(i));
        vec.push_back(s);
    }
    return vec;
}

void MatrixProblemClientHandler::handleClient(int socketID) {
    string line = "";
    string serverSolution = "";

    vector<vector<double>> allLines;
    vector<vector<State<Point>>> matrix;
    int lineNumCounter = 0;

    while (true) {
        char buf[1024];
        int numBytesRead = recv(socketID, buf, sizeof(buf), 0);

        if (numBytesRead > 0) {
            for (int i = 0; i < numBytesRead; i++) {
                char c = buf[i];
                if (c == '\n') {
                    if (line.length() > 0) {
                        lineNumCounter++;
                        if (!line.compare("end")) {

                            vector<double> goal = allLines.at(lineNumCounter);
                            Point goalPoint(goal.at(0), goal.at(1));
                            State<Point>* goalState = new State<Point>(goalPoint);
                            allLines.pop_back();
                            vector<double> init = allLines.at(lineNumCounter - 1);
                            Point initPoint(init.at(0), init.at(1));
                            State<Point>* initState = new State<Point>(initPoint);
                            allLines.pop_back();

                            for(size_t i = 0; i < lineNumCounter - 2; i++) {
                                vector<State<Point>> v = convertLineToMatrixRow(allLines.at(i), i);
                                matrix.push_back(v);
                            }

                            SearchableMatrix* searchableMatrix = new SearchableMatrix(initState, goalState, &matrix);

                            /*if (m_cacheManager->isSolutionSaved(line)) {
                                serverSolution = m_cacheManager->getSolution(line);
                            } else {*/
                                serverSolution = m_solver->solve(searchableMatrix);
                                //m_cacheManager->saveSolution(line, serverSolution);
                            //}

                            ssize_t n;

                            // Send message
                            n = write(socketID, serverSolution.c_str(), serverSolution.length());

                            if (n < 0) {
                                close(socketID);
                                return;
                            }

                            serverSolution = "";
                            close(socketID);
                            return;

                        } else {

                            vector<double> lineCostsValues = splitToDoubleByChar(line, ',');
                            allLines.push_back(lineCostsValues);

                            line = "";
                        }
                    }
                } else {
                    line += c;
                }
            }
        } else {
            if (errno == EWOULDBLOCK) {
                continue;
            }
            close(socketID);
            return;
        }
    }
}



