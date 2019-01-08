#ifndef PROJ2_CLIENTHANDLER_H
#define PROJ2_CLIENTHANDLER_H

#include <istream>

//The class determine the type of the talk with the client and how to answer his requirements
class ClientHandler {
public:
    //TODO - check if we really doesn't have to get input&output stream
    virtual void handleClient(int socketID) = 0;
};


#endif //PROJ2_CLIENTHANDLER_H





