/*
 * Added TODO comments by Tetsunari Inamura on 2014-03-02
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#ifndef WIN32
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define SOCKET int
#else
#include <Windows.h>
#endif

int main(int argc, char **argv)
{
	char *servername = "localhost";
	unsigned short port = 9000; //TODO: Magic number

	int i=1;
	while (i < argc) {
		char *opt = argv[i];
		if (*opt != '-') { break; }
		switch(opt[1]) {
		case 's':
			i++;
			servername = argv[i]; i++;
			break;
		case 'p':
			i++;
			port = atoi(argv[i]); i++;
			break;
		default:
			fprintf(stderr, "bad option : %s\n", opt);
			return 1;
		}
	}

	struct sockaddr_in server;
	SOCKET sock;
	char buf[32];
//	int n;

#ifdef WIN32
	WSADATA data;
	int result = WSAStartup(MAKEWORD(2, 0), &data);

	if (result < 0){
		fprintf(stderr, "%d\n", GetLastError());
		exit(1);
	}
#endif
	sock = socket(AF_INET, SOCK_STREAM, 0);

	// Preparation of structure for the socket connection
	server.sin_family = AF_INET;
	server.sin_port = htons(port);
	server.sin_addr.s_addr = inet_addr(servername);
	if (server.sin_addr.s_addr == 0xffffffff) {
		struct hostent *host;

		host = gethostbyname(servername);
		if (host == NULL) {
			return 1;
		}
		server.sin_addr.s_addr = *(unsigned int *)host->h_addr_list[0];
	}

	// Connecting to the server
	int ret = connect(sock, (struct sockaddr *)&server, sizeof(server));
	if (ret < 0) {
		fprintf(stderr, "failed to quit\n");
	}
	send(sock, "SIGMESSAGE,SIGEND,", 18, 0); //TODO: Use exclusive library should be used
	recv(sock, buf, sizeof(buf), 0);
	fprintf(stderr, "SIGVerse world (port[%d]) ended\n", port);  

	return 0;
}
