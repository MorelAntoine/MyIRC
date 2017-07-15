/*
** send_msg_to.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/cmd/message
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Tue May 30 17:33:42 2017 DESKTOP-DHNB9O5
** Last update Wed Jun  7 20:28:38 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<string.h>
#include		"client.h"
#include		"error.h"

static void		send_private_msg(char **params,
					 t_config *config)
{
  char			*str;

  dprintf(config->ssock, ":%s PRIVMSG %s %s",
	  config->nickname, params[0], params[1]);
  if (params[2])
    dprintf(config->ssock, " %s", params[2]);
  str = strtok(NULL, SPACE);
  while (str)
    {
      dprintf(config->ssock, " %s", str);
      str = strtok(NULL, SPACE);
    }
  dprintf(config->ssock, "%s", CRLF);
}

void			send_msg_to(t_config *config)
{
  char			*params[3];

  if (!config->nickname)
    {
      display_error(1, 431, NULL);
      return ;
    }
  params[0] = strtok(NULL, SPACE);
  params[1] = strtok(NULL, SPACE);
  params[2] = strtok(NULL, SPACE);
  if (!params[0] || !params[1])
    {
      display_error(1, 461, NULL);
    }
  send_private_msg(params, config);
}
