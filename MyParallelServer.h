#ifndef PROJ2_MyParallelServer_H
#define PROJ2_MyParallelServer_H

#include "ServerSide.h"
#include <vector>


using namespace server_side;

class MyParallelServer : public Server{
    int m_port;
    int m_socket;
    std::vector<int> m_clientSocketsVector;

public:
    MyParallelServer(int port);
    void serverListen();
    int serverAccept();
    /**
     * the function get int port to listen, open the server and waiting for clients
     * @param port - to listen
     * @param c
     */
    virtual void open(int port/*, ClientHandler c*/);

    /**
     * the function close the server
     */
    virtual void stop();

    virtual void listenToClients();
};


#endif //PROJ2_MyParallelServer_H






