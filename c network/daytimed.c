/* TCP/IP connection "server" */

/*
//TCP/IP Protocol
struct sockaddr_in {
    sa_family_t = sin_family; //Address family
    in_port_t = sin_port;     //Port number
    struct in_addr sin_addr;  //Internet address
    unsigned char sin_zero[sizeof(struct sockaddr) - sizeof(unsigned short int) -
                           sizeof(in_port_t) - sizeof(struct in_addr)]; //Padding
}
*/
/* for 64 bit OS*/
#include <arpa/inet.h> //inet_ntoa()
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>      //time(), ctime()
#include <unistd.h>    //write(),close()

#define MAX_BUF_SIZE 256
#define BACKLOG 5

int main(int argc, char* argv[])
{
    /* Discriptor is identifier for managing the stream (1) */
    int sock;
    struct sockaddr_in sa;

    /* If There are no 2 command line arguments, show usage.*/
    if (argc != 2) {
        fprintf(stderr, "Usage: daytimed port_number\n"); exit(1);
    }
    /* Open the listening socket */
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        /* If it fails, Output error message and exit */
        perror("socket error"); exit(1);
    }

    bzero(&sa, sizeof(sa));             /* Initialize structure sa variable */
    sa.sin_family = AF_INET;            /* Use Internet address */
    sa.sin_port = htons(atoi(argv[1])); /* Use port and conver to network biteorder with htons() */

    /* Convert INADDR_ANY constant value to network byte order,
     * meaning that it listens for all connections
     */
    sa.sin_addr.s_addr = htonl(INADDR_ANY);

    /*ifndef ----- endif( Compile only once ( avoid duplicate definitions ) */
    #ifndef NOREUSEADDR
        int nonzero = 1;
        /* Set socket options for debugging */
        setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &nonzero, sizeof(nonzero));
    #endif

    /* Bind the opened socket to the listening address and port set in the structure sa */
    if (bind(sock, (struct sockaddr*) & sa, sizeof(sa)) < 0) {
        perror("bind error"); exit(1);
    }
    /* Start waiting for connection */
    if (listen(sock, BACKLOG) < 0) {
        perror("listen error"); exit(1);
    }

    /* Discriptor (2)*/
    int csock; /* client socket */
    struct sockaddr_in csa;

    char buf[MAX_BUF_SIZE + 1];
    int len;
    int n;
    time_t seconds;

    /* Handle connections from clients in an infinite loop  */
    while (1) {
        /* Create a new socket to be used for communication to the client
         * and wait until there is a connection from the client( accept waits )
         */

        n = sizeof(csa);
        if ((csock = accept(sock, (struct sockaddr*) & csa, (socklen_t*)&n)) < 0) {
            perror("connect error"); exit(1);
        }
        /* Display connection destination information */
        printf("Connected from %s port %d\n", inet_ntoa(csa.sin_addr), ntohs(csa.sin_port));
        /* initiatlize a variable to store time information */
        seconds = time(NULL);
        /* Store the current time as a character string in buf  */
        snprintf(buf, MAX_BUF_SIZE, "%s\r\n", ctime(&seconds));
        /* Write ( Send ) buf to socket */
        write(csock, buf, strlen(buf));
        /* Close the client socketソケットを閉じる */
        close(csock);
        /* To process the next socket */
    }
}