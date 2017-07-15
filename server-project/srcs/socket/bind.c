/*
** bind.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/srcs/socket
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 24 17:59:39 2017 DESKTOP-DHNB9O5
** Last update Tue May 30 00:12:23 2017 DESKTOP-DHNB9O5
*/

#include		"socket.h"

bool			socket_bind(const t_socket sock,
				    const in_addr_t addr,
				    const unsigned short port,
				    t_client *server)
{
  struct sockaddr_in	sin;

  sin.sin_addr.s_addr = addr;
  sin.sin_family = AF_INET;
  sin.sin_port = port;
  if (bind(sock, (const struct sockaddr *)(&sin),
	   sizeof(sin)) == SOCKET_ERROR)
    return (FALSE);
  server->ip = inet_ntoa(sin.sin_addr);
  return (TRUE);
}
