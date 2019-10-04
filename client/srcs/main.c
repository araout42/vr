#include "client.h"

int		recv_data(SOCKET sock)
{
	char	buf[255];
	int		size;

	memset(buf, 0, 255);
	while ((size = recv(sock, buf, 255, 0)) >= 0)
	{
		buf[size] = '\0';
		printf("%s", buf);
		if (!(strcmp(buf, "exit")))
		{
	printf("BLABLABLA");
			send(sock, "exiting...", 10, 0);
			closesocket(sock);
		}
		memset(buf, 0, 255);
	}
	return (0);
}

int		main(void)
{
	int				error;
	SOCKADDR_IN		sin;
	SOCKET			sock;

	#if defined (WIN32)
		WSADATA wsa_data;
		error = wsaStartup(MAKEWORD(2, 2), &wsa_data);
	#else
		error = 0;
	#endif
	if (!error)
	{
		sock = socket(AF_INET, SOCK_STREAM, 0);
		sin.sin_addr.s_addr = inet_addr("127.0.0.1");
		sin.sin_family = AF_INET;
		sin.sin_port = htons(44);
		if (connect(sock, (SOCKADDR *)&sin, sizeof(sin)) != SOCKET_ERROR)
		{
			printf("CONNECTED\n");
			recv_data(sock);
		}
		else
			printf("ERROR");
		closesocket(sock);
	}
	#if defined (WIN32)
		WSAcleanup();
	#endif
	return (0);
}