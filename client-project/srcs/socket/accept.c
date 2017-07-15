/*
** accept.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/socket
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Fri May 26 14:30:38 2017 DESKTOP-DHNB9O5
** Last update Fri May 26 14:30:39 2017 DESKTOP-DHNB9O5
*/

#include		"socket.h"

t_socket		socket_accept(const t_socket sock,
				      struct sockaddr_in *cin)
{
  t_socket		csock;
  socklen_t		socklen;

  socklen = sizeof((*cin));
  csock = accept(sock, (struct sockaddr *)(cin), &socklen);
  if (csock == SOCKET_ERROR)
    return (SOCKET_ERROR);
  return (csock);
}
