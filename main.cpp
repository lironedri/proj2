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
#include "MyPriorityQueue.h"
#include "MatrixProblemSolver.h"
#include "MatrixProblemClientHandler.h"
#include "AlgoBestFirstSearch.h"

using namespace server_side;

int main(int argc, const char *argv[]) {
    Server* server = new MySerialServer();
    Searcher<SearchableMatrix, string>* algoType = new AlgoBestFirstSearch<Point>();
    //Solver<SearchableMatrix, string>* solver = new MatrixProblemSolver(algoType);
    CacheManager<string,string>* cacheManager = new FileCacheManager<string, string>("ps.txt");
    //ClientHandler* clientHandler = new MatrixProblemClientHandler(solver, cacheManager);

    //server->open(5400 ,clientHandler);
    this_thread::sleep_for(chrono::milliseconds(100000000));

    server->stop();
//
//    Point p1(0,0);
//    Point p2(0,1);
//    Point p3(1,0);
//    Point p4(1,1);
//    Point p5(2,0);
//    Point p6(2,1);
//
//    Point p7(2,1);
//
//    State<Point> s1(p1);
//    s1.setCost(6);
//    State<Point> s2(p2);
//    s2.setCost(8);
//    State<Point> s3(p3);
//    s3.setCost(20);
//    State<Point> s4(p4);
//    s4.setCost(2);
//
//    State<Point>* s1 = new State<Point>(p1);
//    s1->setCost(6);
//    State<Point>* s2 = new State<Point>(p2);
//    s2->setCost(8);
//    State<Point>* s3 = new State<Point>(p3);
//    s3->setCost(20);
//    State<Point>* s4 = new State<Point>(p4);
//    s4->setCost(2);
//    State<Point>* s5 = new State<Point>(p5);
//    s5->setCost(7);
//    State<Point>* s6 = new State<Point>(p6);
//    s6->setCost(10);
//
//    State<Point>* s7 = new State<Point>(p7);
//    s7->setCost(10);
//
//    MyPriorityQueue<Point> myPQ;
//    myPQ.myPush(s1);
//    myPQ.myPush(s2);
//    myPQ.myPush(s3);
//    myPQ.myPush(s4);
//    myPQ.myPush(s5);
//    myPQ.myPush(s6);
//
//    State<Point>* ab = myPQ.myTop();
//    cout << to_string(ab->getCost()) << endl;
//    myPQ.myPop();
//    State<Point>* c = myPQ.myTop();
//    cout << to_string(c->getCost()) << endl;
//    myPQ.myPop();
//    State<Point>* bb = myPQ.myTop();
//    cout << to_string(bb->getCost()) << endl;
//    myPQ.myPop();
//    State<Point>* d = myPQ.myTop();
//    cout << to_string(d->getCost()) << endl;
//    myPQ.myPop();
//    State<Point>* e = myPQ.myTop();
//    cout << to_string(e->getCost()) << endl;
//    myPQ.myPop();
//    State<Point>* f = myPQ.myTop();
//    cout << to_string(f->getCost()) << endl;
//    myPQ.myPop();
//
//    myPQ.myCut(s1);
//    bool a = myPQ.myIsExist(s5);
//    State<Point>* s = myPQ.myFind(s7);
//
//
//    vector<State<Point>> v1;
//    v1.push_back(s1);
//    v1.push_back(s2);
//
//    vector<State<Point>> v2;
//    v2.push_back(s3);
//    v2.push_back(s4);
//
//    vector<vector<State<Point>>> matrix;
//    matrix.push_back(v1);
//    matrix.push_back(v2);
//
//    SearchableMatrix myMatrix(s1, s4, matrix);
//
//    vector<State<Point>> allNei = myMatrix.getAllPossibleState(s2);
//    for(size_t i = 0; i < allNei.size(); i++) {
//        cout << to_string(allNei.at(i).getCost()) << endl;
//    }

    return 0;
}