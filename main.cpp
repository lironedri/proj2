#include <iostream>
#include <thread>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "Solver.h"
#include "FileCacheManager.h"
#include "Matrix.h"
#include "Point.h"
#include <vector>
#include "SearchableMatrix.h"

using namespace server_side;

int main(int argc, const char *argv[]) {
//    Server* server = new MySerialServer();
//    Solver<string, string>* solver = new StringReverser();
//    CacheManager<string,string>* cacheManager = new FileCacheManager<string, string>("ps.txt");
//    ClientHandler* clientHandler = new MyTestClientHandler(solver, cacheManager);
//
//    server->open(5400 ,clientHandler);
//    this_thread::sleep_for(chrono::milliseconds(100000000));
//
//    server->stop();

    Point p1(0,0);
    Point p2(0,1);
    Point p3(1,0);
    Point p4(1,1);

    State<Point> s1(p1);
    s1.setCost(6);
    State<Point> s2(p2);
    s2.setCost(8);
    State<Point> s3(p3);
    s3.setCost(20);
    State<Point> s4(p4);
    s4.setCost(2);


    vector<State<Point>> v1;
    v1.push_back(s1);
    v1.push_back(s2);

    vector<State<Point>> v2;
    v2.push_back(s3);
    v2.push_back(s4);

    vector<vector<State<Point>>> matrix;
    matrix.push_back(v1);
    matrix.push_back(v2);

    SearchableMatrix myMatrix(s1, s4, matrix);

    vector<State<Point>> allNei = myMatrix.getAllPossibleState(s2);
    for(size_t i = 0; i < allNei.size(); i++) {
        cout << to_string(allNei.at(i).getCost()) << endl;
    }

    return 0;
}