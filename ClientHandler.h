#ifndef PROJ2_CLIENTHANDLER_H
#define PROJ2_CLIENTHANDLER_H

#include <istream>
namespace server_side {
//The class determine the type of the talk with the client and how to answer his requirements
    class ClientHandler {
    public:
        virtual void handleClient(int socketID) = 0;
    };
}


#endif //PROJ2_CLIENTHANDLER_H





