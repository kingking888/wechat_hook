#include "pch.h"
#include <WINSOCK2.H>


SOCKET Connect_to_Server()
{
	SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (client == INVALID_SOCKET)
	{
		return 0;
	}

	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(9527);
	serAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	if (connect(client, (sockaddr*)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
	{  
		closesocket(client);
		return 0;
	}
	return client;
}