#include "server.h"

int			accept_connection(void)
{
	pid_t	fork_id;
	pid_t	fork_id2;

	while((g_sock.csock[*(g_sock.sock_nbr)] = accept(g_sock.sock, ((SOCKADDR *)&(g_sock.csin)), &(g_sock.crecsize))) >= 0)
	{
		fork_id = fork();
		if (fork_id == 0)
		{
			printf("new client connected id =  %d\nsock = %d\n", (*(g_sock.sock_nbr))+1, g_sock.csock[*(g_sock.sock_nbr)]);
			write(g_sock.csock[*(g_sock.sock_nbr)], "HELLO\n", 6);
			(*(g_sock.sock_nbr))++;
			closesocket(g_sock.csock[*(g_sock.sock_nbr)]);
			exit(0);
		}
		fork_id2 = fork();
		if (fork_id2 == 0)
		{
			send_recv();
		}
	}
	return (fork_id);
}

void		setsock()
{
	g_sock.crecsize = sizeof(g_sock.csin);

	#if defined (WIN32)
		WSADATA wsa_data;
		g_sock.error = wsaStartup(MAKEWORD(2, 2), &wsa_data);
	#else
		g_sock.error = 0;
	#endif
	g_sock.recsize = sizeof(g_sock.sin);
	g_sock.csock = mmap(NULL, sizeof(SOCKET) * 1024, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	g_sock.sock_nbr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
}


int			shlanch(void)
{
	setsock();
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
				g_sock.sock_err = listen(g_sock.sock, 1024);
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

