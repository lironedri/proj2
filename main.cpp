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
using namespace std;

int main(int argc, const char *argv[]) {
    Server* server = new MySerialServer();
    Searcher<Point, string>* algoType = new AlgoBestFirstSearch<Point, string>();
    Solver<SearchableMatrix*, string>* solver = new MatrixProblemSolver(algoType);
    CacheManager<string,string>* cacheManager = new FileCacheManager<string, string>("ps.txt");
    ClientHandler* clientHandler = new MatrixProblemClientHandler(solver, cacheManager);

    server->open(5400 ,clientHandler);
    this_thread::sleep_for(chrono::milliseconds(1000000000000));

    server->stop();

    return 0;
}