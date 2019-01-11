#include <iostream>
#include <thread>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "Solver.h"
#include "FileCacheManager.h"

using namespace server_side;

int main(int argc, const char *argv[]) {
    Server* server = new MySerialServer();
    Solver<string, string>* solver = new StringReverser();
    CacheManager<string,string>* cacheManager = new FileCacheManager<string, string>("ps.txt");
    ClientHandler* clientHandler = new MyTestClientHandler(solver, cacheManager);

    server->open(5400 ,clientHandler);
    this_thread::sleep_for(chrono::milliseconds(100000000));

    server->stop();


    return 0;
}