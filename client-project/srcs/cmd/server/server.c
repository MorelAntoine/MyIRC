/*
** server.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/cmd/server
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Fri May 26 15:15:30 2017 DESKTOP-DHNB9O5
** Last update Fri Jun  2 16:43:44 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>
#include		"client.h"
#include		"error.h"

static bool		start_connection(t_socket *ssock,
					 const char * const ip,
					 const int port)
{
  if ((*ssock) != SOCKET_ERROR)
    close_socket((*ssock));
  (*ssock) = create_socket("TCP");
  if ((*ssock) == SOCKET_ERROR)
    return (FALSE);
  if (!socket_connect((*ssock), inet_addr(ip), htons(port)))
    {
      close_socket((*ssock));
      (*ssock) = SOCKET_ERROR;
      return (FALSE);
    }
  return (TRUE);
}

static void		set_user(t_socket ssock)
{
  char			*user;

  user = getenv("USER");
  if (user)
    dprintf(ssock, "NICK %s%s", user, CRLF);
  if (user)
    dprintf(ssock, "USER Anonymous unknown unknown :%s%s",
	    user,
	    CRLF);
}

void			server(t_config *config)
{
  char			*info_server;
  char			*ip;
  char			*_port;
  int			port;

  info_server = strtok(NULL, SPACE);
  if (!info_server)
    {
      display_error(1, 461, NULL);
      return ;
    }
  ip = strtok(info_server, ":");
  _port = strtok(NULL, SPACE);
  if (!ip || !_port)
    {
      display_error(1, 402, NULL);
      return ;
    }
  port = atoi(_port);
  if (!start_connection(&config->ssock, ip, port))
    display_error(1, 402, NULL);
  set_user(config->ssock);
}
