#ifndef PROJ2_SERVERSIDE_H
#define PROJ2_SERVERSIDE_H
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>

#include "ClientHandler.h"

namespace server_side {
    class Server{
    public:
        /**
         * the function get int port to listen, open the server and waiting for clients
         * @param port - to listen
         * @param c - type of talk with the client
         */
        virtual void open(int port, ClientHandler* c) = 0;

        /**
         * the function close the server
         */
        virtual void stop() = 0;


    };

}



#endif //PROJ2_SERVERSIDE_H





