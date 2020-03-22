/* TCP/IP connection "client" */
/* Port number is 8080 */

#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>

#define MAXPENDING 5
#define RCVBUFSIZE 32

void DieWithError(char* errorMessage);

int main(int argc, char* argv[])
{
	int sock;                       /* Server's socket discriptor */
	struct sockaddr_in echoServAddr;    /* Local Address */

	char* servIP;                                /* Server's IP address  */
	char servIPBuffer[RCVBUFSIZE] = " ";
	char* echoString;                            /* String that sends echoServer*/
	char echoBuffer[RCVBUFSIZE];                 /* String sentence's Buffer*/
	unsigned int clntStringLen;
	int byteRcvd, totalBytesRcvd;
	

	printf("<Server Port> is 4000\n");
	servIP = servIPBuffer;
	printf("<Server IP address> is %s\n", servIP);

	/* Create the socket */
	if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		DieWithError("socket() failed");

	/* Initialize and set up the server structure */
	memset(&echoServAddr, 0, sizeof(echoServAddr));
	echoServAddr.sin_family = AF_INET;
	echoServAddr.sin_addr.s_addr = inet_addr(servIP);
	echoServAddr.sin_port = htons(4000); /* Don't forget network byte order */

	/* Bind the socket to an address */
	if (connect(sock, (struct sockaddr*) & echoServAddr, sizeof(echoServAddr)) < 0)
		DieWithError("connect() failed");

	/* Loop forever, accepting all conections */
	for (;;) {
		printf("send server a message: "); scanf("%s", echoBuffer);
		clntStringLen = strlen(echoBuffer);

		if (send(sock, echoString, clntStringLen, 0) != clntStringLen)
			DieWithError("send() failed");

		if (strcmp("quit", echoBuffer) == 0)
			break;

		totalBytesRcvd = 0;
		printf("Received a message from server: ");

		while (totalBytesRcvd < clntStringLen) {
			if ((byteRcvd = recv(sock, echoBuffer, RCVBUFSIZE - 1, 0)) <= 0)
				DieWithError("recv() failed or connection closed prematurely");
			totalBytesRcvd += byteRcvd;
		}

		echoBuffer[clntStringLen] = '\0';
		if (strcmp("quit", echoBuffer) == 0)
			break;
		else
			printf("%s\n", echoBuffer);

	}

	printf("Disconnecting...\n");
	close(sock);
	return 0;
}

void DieWithError(char* errorMessage) {
	perror(errorMessage); exit(1);
}