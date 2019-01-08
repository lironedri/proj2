#include "MyParallelServer.h"

MyParallelServer::MyParallelServer(int port) {
    this->m_port = port;
    this->m_socket = -1;
}

//TODO
void MyParallelServer::open(int port/*, ClientHandler c*/){
    this->m_port = port;
    /* First call to socket() function */
    this->m_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (this->m_socket < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
}

void MyParallelServer::listenToClients() {
    struct sockaddr_in serv_addr;

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(this->m_port);

    /* Now bind the host address using bind() call.*/
    if (bind(this->m_socket, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(this->m_socket, 5);
}


int MyParallelServer::serverAccept() {
    int clilen, clientSocket;
    struct sockaddr_in cli_addr;

    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    clientSocket = accept(this->m_socket, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (clientSocket < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    this->m_clientSocketsVector.push_back(clientSocket);
    return clientSocket;
}

void MyParallelServer::stop() {
    for (auto &it: this->m_clientSocketsVector) {
        close(it);
    }

    close(this->m_socket);
}
