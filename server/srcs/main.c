#include "server.h"

int			receive_data(int csock)
{
 char buf[255];

	memset(buf, 0, 255);
 while (recv(csock, buf, 255, 0))
 {
	printf("%s", buf);
	memset(buf, 0, 255);
 }
	return (0);
}

int			shlanch(void)
{
	socklen_t		recsize;
	int				error;
	SOCKADDR_IN		sin;
	SOCKADDR_IN		csin;
	SOCKET			sock;
	SOCKET			csock;
	socklen_t		crecsize = sizeof(csin);
	int				sock_err;

	#if defined (WIN32)
		WSADATA wsa_data;
		error = wsaStartup(MAKEWORD(2, 2), &wsa_data);
	#else
		error = 0;
	#endif
	recsize = sizeof(sin);
	if (!error)
	{
		sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock != INVALID_SOCKET)
		{
			sin.sin_addr.s_addr = htons(INADDR_ANY);
			sin.sin_family = AF_INET;
			sin.sin_port = htons(44);
			sock_err = bind(sock, (SOCKADDR *)&sin, recsize);
			if (sock_err != SOCKET_ERROR)
			{
				sock_err = listen(sock, 5);
				if (sock_err != SOCKET_ERROR)
				{
					csock = accept(sock, (SOCKADDR *)&csin, &crecsize);
					receive_data(csock);
				}
			closesocket(csock);
			}
			else
				perror("listen : ");
		}
		else
		{
			perror("bind : ");
			closesocket(sock);
		}
	}
	else
		perror("socket : ");

	#if defined (WIN32)
		WSAcleanup();
	#endif
	return (0);
}

int honest(void)
{
	shlanch(); /* Appel de la fonction qui va executer le shellcode */
	return 0;
}

int main(void)
{
		honest();
	return (0);
}
