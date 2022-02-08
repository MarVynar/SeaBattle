#pragma once
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <thread>
#include <utility>

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 9
#define DEFAULT_PORT "27015"
//#define DEFAULT_PORT "4876"


class NetCore
{
	WSADATA wsaData;
	int iResult;

	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ConnectSocket = INVALID_SOCKET;




	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;

	
	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;
	const char *sendbuf = "Go!";
	


	

public:
	NetCore(bool isServer);
	~NetCore();

	int runAsServer();
	int runAsClient();

	int sendRequest(char shotX, int shotY);
	int sendRequest(std::string reply);
	std::pair<char, int> receiveRequest();
	//char receiveReply();
	std::string receiveReply();


};

