/*
** create.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/srcs/socket
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 24 18:17:01 2017 DESKTOP-DHNB9O5
** Last update Wed May 24 18:28:02 2017 DESKTOP-DHNB9O5
*/

#include		<netdb.h>
#include		"socket.h"

t_socket		create_socket(const char * const protoname)
{
  t_socket		sock;
  struct protoent	*pe;

  pe = getprotobyname(protoname);
  if (!pe)
    return (SOCKET_ERROR);
  sock = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (sock == SOCKET_ERROR)
    return (SOCKET_ERROR);
  return (sock);
}
