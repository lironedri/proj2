#include "MatrixProblemClientHandler.h"
#include <sys/socket.h>
#include <unistd.h>
#include "FileCacheManager.h"


void MatrixProblemClientHandler::handleClient(int socketID) {
    string problem = "";
    string ans = "";
    while (true) {
        char buf[1024];
        int numBytesRead = recv(socketID, buf, sizeof(buf), 0);

        if (numBytesRead > 0) {
            for (int i = 0; i < numBytesRead; i++) {
                char c = buf[i];
                if (c == '\n') {
                    if (problem.length() > 0) {
                        if (!problem.compare("end")) {
                            close(socketID);
                            return;
                        }
                        // FileCacheManager<string, string> strCM;
//                            if (strCM.isSolutionSaved(problem)) {
//                                //ans = cacheManager->popSolution(problem);
//                            } else {
//                                ans = solver->solve(problem);
//                                cacheManager->pushSolution(problem, ans);
//                            }
                        //ans = ans + "\n";
                        for(int i = problem.length(); i >= 0; i--) {
                            ans += problem[i];
                        }
                        ssize_t n;

                        // Send message
                        n = write(socketID, ans.c_str(), ans.length());

                        if (n < 0) {
                            close(socketID);
                            return;
                        }

                        ans = "";
                        problem = "";
                    }
                } else problem += c;
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