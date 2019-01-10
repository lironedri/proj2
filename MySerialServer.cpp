#include "MySerialServer.h"
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

/**
 * open thread to make communicate by
 * @param port
 * @param c
 */
void server_side::MySerialServer::open(int port,ClientHandler *c) {
    ServerStruct *params;
    params = new ServerStruct();
    params->port = port;
    params->clientHandler = c;
    //boolean indicator to stop the thread
    params->shouldStop = &shouldStop;
    pthread_t thread;
    //the thread start working
    int a = pthread_create(&thread, nullptr, serverThread, params);
    //list of threads to remember verify that the all threads closed.
    threadList.push_back(thread);
}

/**
 * close the server - wait for all threads to stop
 */
void server_side::MySerialServer::stop() {
    shouldStop = true;
    for (int i=0; i<threadList.size(); i++) {
        pthread_join(threadList[i], nullptr);
    }
}

/**
 * that what the treade do when he create
 * @param arg
 * @return
 */
void *MySerialServer::serverThread(void *arg) {
    //cast the args to pointer to the server struct
    ServerStruct *args = (ServerStruct *) arg;

    int mainSocket; // main socket fileDescriptor
    int newsockfd; // new socket fileDescriptor
    int clilen;

    struct sockaddr_in serv_addr, cli_addr;


    //creating socket object
    mainSocket = socket(AF_INET, SOCK_STREAM, 0);
    //if creation faild
    if (mainSocket < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    //Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET; // tcp server
    serv_addr.sin_addr.s_addr = INADDR_ANY; //server ip (0.0.0.0 for all incoming connections)
    serv_addr.sin_port = htons(args->port); //init server port

    //bind the host address using bind() call
    if (bind(mainSocket, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        //if binding faild
        perror("ERROR on binding");
        exit(1);
    }


    //start listening for the clients using the main socket
    listen(mainSocket, 1);
    clilen = sizeof(cli_addr);


    while (!*args->shouldStop) {
        timeval timeout;
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;
        setsockopt(mainSocket, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        //accept actual connection from the client
        newsockfd = accept(mainSocket, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);


        //if connections with the client failed
        if (newsockfd < 0) {
            if(*args->shouldStop){
                break;
            }
            if (errno == EWOULDBLOCK) {
                continue;
            }
            perror("ERROR on accept");
            exit(1);
        }
        //the hendler client take care of the client requirmens
        args->clientHandler->handleClient(newsockfd);

    }

    close(mainSocket);
    delete (args->clientHandler);
    delete (args);
    return nullptr;
}




