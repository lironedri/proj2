#include <iostream>
#include "MyParallelServer.h"
#include "SocketWriteRead.h"
#include "Client.h"

void StartServer();

void StartClient();

int main(int argc, const char *argv[]) {


 StartServer();
// StartClient();

    pthread_exit(NULL);

}


void StartClient() {
    int clientSocket;
    SocketWriteRead socketWriteRead;
    string msg;

    Client client("127.0.0.1", 5400);
    //dekel hayafa
    client.connectClient();

    client.clientWrite("hi");
//    client.clientWrite((char) '\0');
//    cout << client.clientRead((char) '\0') << endl;
//    client.clientClose();
}

void StartServer() {
    int clientSocket;
    SocketWriteRead socketWriteRead;
    string msg;

    MyParallelServer pServer(5402);
    pServer.listenToClients();
    clientSocket = pServer.serverAccept();

    while (true) {
        cout << socketWriteRead.socketRead(clientSocket, (char) '\n') << endl;
    }
//    cin >> msg;
//    socketWriteRead.socketWrite(m_clientSocket, msg);
//    socketWriteRead.socketWrite(m_clientSocket, '\0');
//    server.serverClose();
}

