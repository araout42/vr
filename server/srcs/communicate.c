#include "server.h"

void		list_client()
{
	int		client_nbr = *(g_sock.sock_nbr);
	int		i = 1;
	
	if (!client_nbr)
		{
			printf("NO CLIENT\n");
		return ;
		}
	while (--client_nbr)
	{
		printf("client %d, socket = %d\n", i, g_sock.csock[i - 1]);
		i++;
	}
}

int			choose_client(void)
{
	char	buf[255];
	int		n = -1;
	int		flag = 0;
	int		read_nb = 0;
	while (flag != 1)
	{
		list_client();
		printf("Choose a client, or wait for connection\n");
		write(1, "\n>>", 3);
		read_nb = read(0, buf, 5);
		buf[read_nb] = '\0';
		n = atoi(buf);
		if (n <= 0 || n > *(g_sock.sock_nbr))
			printf("\tWrong choice...\n\n");
		else
		{
			flag = 1;
			printf("\tYou chose client %d\n", n);
			g_sock.curr_sock = n - 1;
		}
	}
	return (0);
}


int			send_recv(void)
{
//	int		fork_id;

	choose_client();
//	fork_id = fork();
//	if (fork_id == 0)
//		recv_data();
//	else
		send_data();
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
	int		len;

	memset(buf, 0, 255);
	while ((len = read(0, buf, 255)) > 0)
	{
		if (!strcmp(buf, "exit\n"))
		{
			closesocket(g_sock.csock[g_sock.curr_sock]);
			exit(0);
		}
		write(g_sock.csock[g_sock.curr_sock], buf, len - 1);
		printf("sending %s, on socke nbr %d\n ", buf, g_sock.csock[g_sock.curr_sock]);
		memset(buf, 0, 255);
	}
	return (0);
}
