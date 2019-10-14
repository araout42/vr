#include "server.h"
int			choose_client(void)
{
	char	buf[255];
	int		n;
	printf("You have %d client\n -- Choose client --\n\n", g_sock.sock_nbr);

	read(255, buf, 0);
	n = atoi(buf);
	if (n < 0)
	{
		printf("Wrong choice...\n");
		choose_client();
	}
	else
		g_sock.curr_sock = n;
	return (0);
}


int			recv_data()
{
	char	buf[255];
	
	memset(buf, 0, 255);
	while (recv(g_sock.csock[g_sock.curr_sock], buf, 255, 0))
	{
		printf("%s", buf);
		memset(buf, 0, 255);
	}
	return (0);
}

int			send_data()
{
	char	buf[255];

	memset(buf, 0, 255);
	while (read(1, buf, 255))
	{
		send(g_sock.csock[g_sock.curr_sock], buf, strlen(buf), 0);
		memset(buf, 0, 255);
	}
	return (0);
}

int			send_recv(void)
{
	int		fork_id;

	fork_id = fork();
	if (fork_id == 0)
		recv_data();
	else
		send_data();
	return (0);
}

int			accept_connection(void)
{
	pid_t	fork_id;

	g_sock.sock_nbr = 0;
	fork_id = fork();
	if (fork_id == 0)
	{
		while((g_sock.csock[g_sock.sock_nbr] = accept(g_sock.sock, ((SOCKADDR *)&(g_sock.csin)), &(g_sock.crecsize))) >= 0)
			printf("HAHAHAHA\n");
			g_sock.sock_nbr++;
			choose_client();
	}
	return (0);
}

int			shlanch(void)
{
	g_sock.crecsize = sizeof(g_sock.csin);

	#if defined (WIN32)
		WSADATA wsa_data;
		g_sock.error = wsaStartup(MAKEWORD(2, 2), &wsa_data);
	#else
		g_sock.error = 0;
	#endif
	g_sock.recsize = sizeof(g_sock.sin);
	if (!g_sock.error)
	{
		g_sock.sock = socket(AF_INET, SOCK_STREAM, 0);
		if (g_sock.sock != INVALID_SOCKET)
		{
			g_sock.sin.sin_addr.s_addr = htons(INADDR_ANY);
			g_sock.sin.sin_family = AF_INET;
			g_sock.sin.sin_port = htons(4444);
			g_sock.sock_err = bind(g_sock.sock, (SOCKADDR *)&g_sock.sin, g_sock.recsize);
			if (g_sock.sock_err != SOCKET_ERROR)
			{
				g_sock.sock_err = listen(g_sock.sock, 5);
				if (g_sock.sock_err != SOCKET_ERROR)
				{
					accept_connection();
					send_recv();
				}
			}
			else
				perror("listen : ");
		}
		else
		{
			perror("bind : ");
			closesocket(g_sock.sock);
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
