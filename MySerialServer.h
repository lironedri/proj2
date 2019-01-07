#ifndef PROJ2_MYSERIALSERVER_H
#define PROJ2_MYSERIALSERVER_H

#include "ServerSide.h"

using namespace server_side;

class MySerialServer : public Server{
public:
    /**
     * the function get int port to listen, open the server and waiting for clients
     * @param port - to listen
     * @param c
     */
    virtual void open(int port, ClientHandler c) = 0;

    /**
     * the function close the server
     */
    virtual void stop() = 0;

    virtual void listenToClients() = 0;
};


#endif //PROJ2_MYSERIALSERVER_H
