/* TCP/IP connection "server" */
/* Port number is 4000 */

#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define MAXPENDING 5
#define RCVBUFSIZE 32

void DieWithError(char* errorMessage);

int main(int argc, char* argv[])
{
	int servSock;                       /* Server's socket discriptor */
	struct sockaddr_in echoServAddr;    /* Local Address */
	unsigned short echoServPort = 4000; /* Server Port */

	int clntSock;                       /* Client's socket discriptor */
	struct sockaddr_in echoClntAddr;    /* Client Address */
	int clntLen = sizeof(echoClntAddr);
	int nonzero = 1;                    /* For setsockopt */

	printf("<Server Port> is 4000\n");
	//if (argc != 2) {
		//fprintf(stderr, "USAGE: %s <Server Port>\n", argv[0]); exit(1);
	//}

	/* Create the socket */
	if ((servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		DieWithError("socket() failed");

	/* Want to reuse the local address */
	setsockopt(servSock, SOL_SOCKET, 0, &nonzero, sizeof(nonzero));

	/* Initialize and set up the server structure */
	memset(&echoServAddr, 0, sizeof(echoServAddr));
	echoServAddr.sin_family = AF_INET;
	echoServAddr.sin_port = htons(4000); /* Don't forget network byte order */

	/* Bind the socket to an address */
	if (bind(servSock, (struct sockaddr*) & echoServAddr, sizeof(echoServAddr)) < 0)
		DieWithError("bind() failed");

	/* Wait for incoming connections */
	if ((listen(servSock, MAXPENDING)) < 0)
		DieWithError("listen() failed");

	char word[RCVBUFSIZE];
	char echoBuffer[RCVBUFSIZE];
	int recvMsgsize;

	/* Loop forever, accepting all conections */
	for (;;) {
	    printf("Connecting...\n");

		if ((clntSock = accept(servSock, (struct sockaddr*) & echoClntAddr, (socklen_t*)&clntLen)) < 0)
			DieWithError("accept() failed");

		if ((recvMsgsize = recv(clntSock, echoBuffer, RCVBUFSIZE, 0)) < 0)
			DieWithError("recv() failed");

		while (recvMsgsize > 0) {
			echoBuffer[recvMsgsize] = '\0';

			if ((strcmp(echoBuffer, "quit") == 0)
				break;
			else
				printf("%s\n", echoBuffer);

			/*  Check the receved value whether remained or not*/
			if ((recvMsgsize = recv(clntSock, echoBuffer, RCVBUFSIZE, 0)) < 0)
				DieWithError("recv() failed");
		}

		printf("send client a message: "); scanf("%s", echoBuffer);

		if (send(clntSock, echoBuffer, recvMsgsize, 0) < 0)
			DieWithError("send() failed");

		if ((strcmp(echoBuffer, "quit") == 0)
			break;
		
		printf("Disconnecting...\n");
		close(clntSock);
	}

	return 0;
}

void DieWithError(char* errorMessage) {
	perror(errorMessage); exit(1);
}