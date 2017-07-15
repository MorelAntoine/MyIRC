/*
** socket.h for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/includes
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Fri May 26 14:28:48 2017 DESKTOP-DHNB9O5
** Last update Fri May 26 14:29:20 2017 DESKTOP-DHNB9O5
*/

#ifndef				SOCKET_H_
# define			SOCKET_H_

/*
** INCLUDES
*/

# include			<arpa/inet.h>
# include			<sys/types.h>
# include			<sys/socket.h>
# include			<unistd.h>
# include			"bool.h"

/*
** DEFINES
*/

# ifndef			CLOSE_SOCKET
#  define			close_socket(int) close(int);
# endif				/* !CLOSE_SOCKET */

# ifndef			CRLF
#  define			CRLF "\r\n"
# endif				/* !CRLF */

# ifndef			LISTEN_LIMIT
#  define			LISTEN_LIMIT 4
# endif				/* !LISTEN_LIMIT */

# ifndef			SOCKET_ERROR
#  define			SOCKET_ERROR -1
# endif				/* !SOCKET_ERROR */

/*
** TYPEDEFS
*/

typedef				int t_socket;

/*
** PROTOTYPES
*/

t_socket			create_socket(const char * const protoname);
bool				socket_bind(const t_socket sock,
					    const unsigned long addr,
					    const unsigned short port);
bool				socket_listen(const t_socket sock,
					      const int limit);
t_socket			socket_accept(const t_socket sock,
					      struct sockaddr_in *cin);
bool				socket_connect(const t_socket sock,
					       const unsigned long addr,
					       const unsigned short port);

#endif				/* !SOCKET_H_ */
