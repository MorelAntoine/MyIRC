/*
** part.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/cmd/channel
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Tue May 30 17:31:03 2017 DESKTOP-DHNB9O5
** Last update Thu Jun  1 15:44:47 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		<string.h>
#include		"client.h"
#include		"error.h"

void			part(t_config *config)
{
  char			*chname;

  if (!config->nickname)
    {
      display_error(1, 431, NULL);
      return ;
    }
  chname = strtok(NULL, SPACE);
  if (!chname)
    {
      display_error(1, 461, NULL);
      return ;
    }
  dprintf(config->ssock, "PART %s%s", chname, CRLF);
}
