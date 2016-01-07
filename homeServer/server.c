//CODE FROM http://www.cs.rpi.edu/courses/sysprog/sockets/server.c

/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <fcntl.h>


void connectToClient(int argc, char *argv[]) {
    //Start initializing sockets and the server
    int sockfd, newsockfd, portno, clilen, n;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
       error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    //Stop initializing sockets and the server


    //Start binding the port
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
        sizeof(serv_addr)) < 0) 
        error("ERROR on binding");

        printf("server listens\n");
    while (1){
        listen(sockfd,5);

        clilen = sizeof(cli_addr);

        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        
        char clntName[INET_ADDRSTRLEN];
        char client_address[INET_ADDRSTRLEN+7];
        if(inet_ntop(AF_INET,&cli_addr.sin_addr.s_addr,clntName,sizeof(clntName)) != 1){
           snprintf(client_address, sizeof(client_address), "%s,%d", clntName, ntohs(cli_addr.sin_port));
           //printf("------------------%s\n", client_address);

        } else {
           printf("Unable to get address\n"); // i just fixed this to printf .. i had it as print before
        }
        printf("server accepts connection\n");
        //go to thread
        if (newsockfd < 0) 
             error("ERROR on accept");

        n = read(newsockfd, buffer, 255);
        //n = write (newsockfd, "(105,0,)\n", sizeof("(105,0,)"));
        if (n<0) error("ERROR reading from socket");
        if (strcmp(buffer, "1") == 0) {
            printf("client said: %s \n", buffer);
            int file;
            file = open("/dev/ttyACM0", O_RDWR);
            char str[2] = "1";
            if(write(file, &str, 2) == -1) {
                perror("perror output: ");
            }
            sleep(1);
            close(file);
        }
    }
        close(sockfd);
}

int main(int argc, char *argv[])
{

    connectToClient(argc, argv);

}