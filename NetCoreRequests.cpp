#include "NetCore.h"

int NetCore::sendRequest(char shotX, int shotY)
{

	int iSendResult = 0;
	
	std::string sendbuf;
	sendbuf.push_back(shotX);
	
	sendbuf += std::to_string(shotY);

	
	if (iSendResult != SOCKET_ERROR) {
	 
		std::cout << "Sending request " << sendbuf.c_str()<<"." << std::endl;
		iSendResult = send(ConnectSocket, sendbuf.c_str(), strlen(sendbuf.c_str()) + 1, 0);

		if (iSendResult == SOCKET_ERROR) {
			printf("send failed with error: %d\n", WSAGetLastError());
			closesocket(ConnectSocket);
			WSACleanup();
			return 1;
		}
	
	}
}

int NetCore::sendRequest(std::string reply)
{
	int iSendResult = 0;

	if (iSendResult != SOCKET_ERROR) {

		/*char* replyMessage = new char[2];
		replyMessage[0] = reply;
		replyMessage[1] = '\0';*/

		std::cout << "Sending reply " <<reply.c_str() << "." << std::endl;
		iSendResult = send(ConnectSocket, reply.c_str(), reply.length()+1, 0);

		if (iSendResult == SOCKET_ERROR) {
			printf("send failed with error: %d\n", WSAGetLastError());
			closesocket(ConnectSocket);
			WSACleanup();
			return 1;
		}
	
	}
}

std::pair<char, int> NetCore::receiveRequest()
{
	iResult = recv(ConnectSocket, recvbuf, recvbuflen + 1, 0);

	if (recvbuf == "Go!") {
		std::cout << recvbuf << std::endl;
		return std::make_pair(0, 0);

	}
	else {


	char* tmp = new char(strlen(recvbuf));
	tmp[0] = recvbuf[1];
	if (recvbuf[2] == '0') {
		tmp[1] = recvbuf[2];
	}
	else {
		tmp[1] = recvbuf[2];
		tmp[2] = recvbuf[3];
	}

	int result = atoi(tmp);

		return std::make_pair(recvbuf[0], result);
	}
}

//char NetCore::receiveReply()
std::string  NetCore::receiveReply()
{
	iResult = recv(ConnectSocket, recvbuf, recvbuflen + 1, 0);

	std::cout << "RecvBuf" << recvbuf << "!" << std::endl;
	//return recvbuf[0];
	return recvbuf;
}