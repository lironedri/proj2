#include <iostream>
#include <thread>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"


using namespace server_side;
int main(int argc, const char *argv[]) {
    Server* server = new MySerialServer();
    ClientHandler* clientHandler = new MyTestClientHandler;

    server->open(5400 ,clientHandler);
    this_thread::sleep_for(chrono::milliseconds(100000000));

    server->stop();


    return 0;
}