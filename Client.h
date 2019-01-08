#ifndef PROJ2_CLIENT_H
#define PROJ2_CLIENT_H


#include <string>
#include "SocketWriteRead.h"

using namespace std;

class Client {
    int m_socket,m_port;
    string m_ip;
    SocketWriteRead m_socketWriteRead;
public:
    Client(string ip, int port);
    void connectClient();
    void clientWrite(string data);
    int getSocket();
};


#endif //PROJ2_CLIENT_H





