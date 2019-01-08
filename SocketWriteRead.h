#ifndef PROJ2_SOCKETWRITEREAD_H
#define PROJ2_SOCKETWRITEREAD_H


#include <string>
using namespace std;

class SocketWriteRead {
public:
    void socketWrite(int socket, string data);
    void socketWrite(int socket, char c);
    string socketRead(int socket, char delimiter);
    string socketRead(int socket, unsigned long length);
};



#endif //PROJ2_SOCKETWRITEREAD_H










