/* TCP/IP connection "client" */

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

#define MAX_BUF_SIZE 255


int main(int argc, char* argv[])
{
    /* Discriptor is identifier for managing the stream (1) */
    int sock;
    struct sockaddr_in sa;
    char buf[MAX_BUF_SIZE + 1];
    int len;
    char word[MAX_BUF_SIZE + 1];

    /* If There are no 2 command line arguments, show usage.*/
    if (argc != 3) {
        fprintf(stderr, "Usage: daytime ip_address port_number\n"); exit(1);
    }
    /* Open the listening socket */
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        /* If it fails, Output error message and exit */
        perror("socket() error"); exit(1);
    }

    bzero(&sa, sizeof(sa));             /* Initialize structure sa variable */
    sa.sin_family = AF_INET;            /* Use Internet address */
    sa.sin_port = htons(atoi(argv[2])); /* Use port and conver to network biteorder with htons() */

    /* Convert the IP address character notation into a binary value with inet_pton
     * and save it in sa.sin_addr
     */
    if (inet_pton(AF_INET, argv[1], &sa.sin_addr) <= 0) {
        /* If it fails, output error message and exit */
        perror("inet_pton() error"); exit(1);
    }

    while (1) {
        printf("This program connects to %s:%s.\n", argv[1], argv[2]);
        printf(">"); scanf("%s", word);

        if (strcmp(word, "quit") == 0)
            exit(1);
        else /*(strcmp(word, "get") == 0)*/ {
            printf("Connecting...\n");

            if (connect(sock, (struct sockaddr*) & sa, sizeof(sa)) < 0) {
                perror("connect error"); exit(1);
            }

            while ((len = read(sock, buf, MAX_BUF_SIZE)) > 0) {
                buf[len] = '\0';
                printf("%s", buf);
            }
            if (len < 0)
                perror("read error");

            printf("Disconnecting...\n");
            close(sock);
        }
    }

}
