#include "Client.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

void Client::connectClient() {
    struct sockaddr_in serv_addr;
    struct hostent *server;

    /* Create a socket point */
    this->m_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (this->m_socket < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(this->m_ip.c_str());

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(this->m_port);

    /* Now connect to the server */
    if (connect(this->m_socket, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
}

Client::Client(string ip, int port) {
    this->m_ip = ip;
    this->m_port = port;
    this->m_socket = -1;
}

void Client::clientWrite(string data) {
    this->m_socketWriteRead.socketWrite(this->m_socket, data);
}

int Client::getSocket() {
    return this->m_socket;
}

