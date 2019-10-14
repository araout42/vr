#include "client.h"


void		fexit(int	code)
{
	send(sock, "closing socket...\n", 255, 0);
	send(sock, "Exiting client with code : ", 255, 0);
	send(sock, ft_itoa(code), 255, 0);
	closesocket(sock);
	exit(code);
}

int			redir_cmd(char *cmd)
{
	if (!strcmp("exit", cmd))
		fexit(0);
	printf("qeqwe\n");
	return (0);
}

int			recv_data(SOCKET sock)
{
	char	buf[255];
	int		len;

	memset(buf, 0, 255);
	while ((len = recv(sock, buf, 255, 0)) > 0)
	{
		buf[len - 1] = '\0';
		redir_cmd(buf);
		memset(buf, 0, 255);
	}
	return (0);
}

int		main(void)
{
	int				error;
	SOCKADDR_IN		sin;

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
		sin.sin_port = htons(4444);
		if (connect(sock, (SOCKADDR *)&sin, sizeof(sin)) != SOCKET_ERROR)
		{
			recv_data(sock);
			printf("apres send_recv\n");
		}
		else
			perror(NULL);
		closesocket(sock);
	}
	#if defined (WIN32)
		WSAcleanup();
	#endif
	return (0);
}
