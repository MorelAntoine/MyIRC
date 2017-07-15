/*
** connect.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/socket
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Fri May 26 14:30:58 2017 DESKTOP-DHNB9O5
** Last update Fri May 26 14:57:02 2017 DESKTOP-DHNB9O5
*/

#include		"socket.h"

bool			socket_connect(const t_socket sock,
				       const unsigned long addr,
				       const unsigned short port)
{
  struct sockaddr_in	sin;

  sin.sin_addr.s_addr = addr;
  sin.sin_family = AF_INET;
  sin.sin_port = port;
  if (connect(sock, (const struct sockaddr *)(&sin),
	      sizeof(sin)) == SOCKET_ERROR)
    return (FALSE);
  return (TRUE);
}
