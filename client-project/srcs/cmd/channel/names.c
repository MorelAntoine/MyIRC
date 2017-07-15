/*
** names.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/cmd/channel
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Tue May 30 17:30:33 2017 DESKTOP-DHNB9O5
** Last update Thu Jun  1 19:01:36 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		<string.h>
#include		"client.h"
#include		"error.h"

void			names(t_config *config)
{
  char			*chname;

  if (!config->nickname)
    {
      display_error(1, 431, NULL);
      return ;
    }
  chname = strtok(NULL, SPACE);
  if (!chname && config->current_ch == -1)
    {
      display_error(1, 461, NULL);
      return ;
    }
  else if (!chname)
    dprintf(config->ssock, "NAMES %s%s",
	    config->channels[config->current_ch],
	    CRLF);
  else
    dprintf(config->ssock, "NAMES %s%s", chname, CRLF);
}
