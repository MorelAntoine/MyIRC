/*
** socket.h for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/includes
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 24 14:27:19 2017 DESKTOP-DHNB9O5
** Last update Tue May 30 00:24:05 2017 DESKTOP-DHNB9O5
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
# include			"client.h"
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
#  define			LISTEN_LIMIT 42
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
					    const in_addr_t addr,
					    const unsigned short port,
					    t_client *server);
bool				socket_listen(const t_socket sock,
					      const int limit);
t_socket			socket_accept(const t_socket sock,
					      struct sockaddr_in *cin);
bool				socket_connect(const t_socket sock,
					       const unsigned long addr,
					       const unsigned short port);
int				make_select(t_client *client, fd_set *fd_read,
					    fd_set *fd_write);

#endif				/* !SOCKET_H_ */
