/*
** list.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/cmd/channel
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Tue May 30 17:29:57 2017 DESKTOP-DHNB9O5
** Last update Thu Jun  1 16:06:35 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		<string.h>
#include		"client.h"
#include		"error.h"

void			list(t_config *config)
{
  char			*chname;

  if (!config->nickname)
    {
      display_error(1, 431, NULL);
      return ;
    }
  chname = strtok(NULL, SPACE);
  if (!chname)
    dprintf(config->ssock, "LIST%s", CRLF);
  else
    dprintf(config->ssock, "LIST %s%s", chname, CRLF);
}
