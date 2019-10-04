#ifndef SERVER_H
# define SERVER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# if defined (WIN32)
#  include <winsock2.h1>
#  include <windows.h>
#  include <winuser.h>
#  include <ws2tcpip.h>
typedef int		socklen_t;
# elif defined (linux)
#  include <sys/types.h>
#  include <sys/socket.h>
#  include <netinet/in.h>
#  include <arpa/inet.h>
#  define INVALID_SOCKET -1
#  define SOCKET_ERROR -1
#  define closesocket(s) close(s)
typedef struct sockaddr_in	SOCKADDR_IN;
typedef struct sockaddr		SOCKADDR;
typedef int					SOCKET;
# endif

typedef struct				s_sock
{
	socklen_t		recsize;
	int				error;
	SOCKADDR_IN		sin;
	SOCKADDR_IN		csin;
	SOCKET			sock;
	SOCKET			csock;
	int				sock_err;
	socklen_t		crecsize;
}							t_sock;

t_sock						g_sock;

#define MEM 214747477
#endif
