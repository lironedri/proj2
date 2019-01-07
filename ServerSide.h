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
        virtual void open(int port, ClientHandler c) = 0;

        /**
         * the function close the server
         */
        virtual void stop() = 0;
    };



    int serverListen() {
        int sockfd, newsockfd, portno, clilen;
        struct sockaddr_in serv_addr, cli_addr;

        /* First call to socket() function */
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("ERROR opening socket");
            exit(1);
        }

        /* Initialize socket structure */
        bzero((char *) &serv_addr, sizeof(serv_addr));
        portno = 5001;

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);

        /* Now bind the host address using bind() call.*/
        if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("ERROR on binding");
            exit(1);
        }

        /* Now start listening for the clients, here process will
           * go in sleep mode and will wait for the incoming connection
        */

        listen(sockfd, 5);
        clilen = sizeof(cli_addr);
    }

    int serverAccept(){
        int sockfd, newsockfd, clilen, n;
        struct sockaddr_in cli_addr;
        char buffer[256];

        /* Accept actual connection from the client */
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        /* If connection is established then start communicating */
        bzero(buffer,256);
        n = read( newsockfd,buffer,255 );

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Here is the message: %s\n",buffer);

        /* Write a response to the client */
        n = write(newsockfd,"I got your message",18);

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        return 0;
    }

    //TODO: function that close the server?
}



#endif //PROJ2_SERVERSIDE_H
