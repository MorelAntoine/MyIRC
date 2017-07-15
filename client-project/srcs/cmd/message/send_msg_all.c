/*
** send_msg_all.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/cmd/message
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Tue May 30 17:33:13 2017 DESKTOP-DHNB9O5
** Last update Wed Jun  7 20:28:30 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<string.h>
#include		"client.h"
#include		"error.h"

void			send_msg_all(const char * const msg,
				     t_config *config)
{
  char			*str;

  if (!config->nickname)
    {
      display_error(1, 431, NULL);
      return ;
    }
  if (config->current_ch == -1)
    {
      display_error(1, 401, config->nickname);
      return ;
    }
  dprintf(config->ssock, ":%s  PRIVMSG %s :%s", config->nickname,
	  config->channels[config->current_ch], msg);
  str = strtok(NULL, SPACE);
  while (str)
    {
      dprintf(config->ssock, " %s", str);
      str = strtok(NULL, SPACE);
    }
  dprintf(config->ssock, "%s", CRLF);
}
