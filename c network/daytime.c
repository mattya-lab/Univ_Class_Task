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
#include <time.h>      
#include <unistd.h>    //write(),close()

using namespace std;

#define MAX_BUF_SIZE 255

int main(int argc, char* argv[])
{
    /* Saved the opened Socket */
    int sock;

    /* Variable that holds connection destination information */
    struct sockaddr_in sa;
    char buf[MAX_BUF_SIZE + 1];
    int len;

    if (argc != 3) {
        fprintf(stderr, "Usage: daytime ip_adrress port_number\n"); exit(1);
    }
    /* Open a socket [A] */
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        /* If it fails, output error message and exit */
        perror("socket() error"); exit(1);
    }

    bzero(&sa, sizeof(sa));             /* Initialize sa variable */
    sa.sin_family = AF_INET;            /* Use Internet address */
    sa.sin_port = htons(atoi(argv[2])); /* Use port and convert to network biteorder*/

    /* Use 192.168.1.1 as the connection destination address */

    /* Convert the IP address character notation into a binary value with inet_pton
     * and save it in sa.sin_addr
     */
    if (inet_pton(AF_INET, argv[1], &sa.sin_addr) <= 0) {
        /* If it fails, output error message and exit */
        perror("inet_pton() error"); exit(1);
    }

    /* Connect to the connection destination set in sa above
     * (note that casting is neccessary because the type is different)
     */
    if (connect(sock, (struct sockaddr*) & sa, sizeof(sa)) < 0) {
        perror("connect error"); exit(1);
    }

    /* Read and write during this time */
    while ((len = read(sock, buf, MAX_BUF_SIZE)) > 0) {
        buf[len] = '\0';
        printf("%s", buf);
    }
    if (len < 0) {
        perror("read() error"); exit(1);
    }
    /* Close a used socket */
    /* To use the socket again, start over from [A] */
    close(sock);
}
