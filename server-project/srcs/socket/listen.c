/*
** listen.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/srcs/socket
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 24 18:06:31 2017 DESKTOP-DHNB9O5
** Last update Fri May 26 11:10:57 2017 DESKTOP-DHNB9O5
*/

#include		"socket.h"

bool			socket_listen(const t_socket sock,
				      const int limit)
{
  if (listen(sock, limit) == SOCKET_ERROR)
    return (FALSE);
  return (TRUE);
}
