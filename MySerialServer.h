#ifndef PROJ2_MYSERIALSERVER_H
#define PROJ2_MYSERIALSERVER_H

#include <list>
#include <vector>
#include "ServerSide.h"
#include "ClientHandler.h"
using namespace std;

using namespace server_side;
namespace server_side {
    class MySerialServer : public Server {
        vector<pthread_t> threadList;
        bool shouldStop = false;
    public:

        void open(int port,ClientHandler *c);

        void stop();

        static void *serverThread(void *arg);

    };

    typedef struct {
        int port;
        ClientHandler *clientHandler;
        bool *shouldStop;
    } ServerStruct;
};



#endif //PROJ2_MYSERIALSERVER_H
