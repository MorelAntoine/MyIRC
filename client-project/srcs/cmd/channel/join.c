/*
** join.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/cmd/channel
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Tue May 30 17:28:54 2017 DESKTOP-DHNB9O5
** Last update Thu Jun  1 18:27:31 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		<string.h>
#include		"client.h"
#include		"error.h"

void			join(t_config *config)
{
  char			*chname;

  if (!config->nickname)
    {
      display_error(1, 432, NULL);
      return ;
    }
  chname = strtok(NULL, SPACE);
  if (!chname)
    {
      display_error(1, 461, NULL);
      return ;
    }
  if (strlen(chname) < 2 || (chname[0] != '&' && chname[0] != '#'))
    {
      display_error(1, 403, chname);
      return ;
    }
  dprintf(config->ssock, "JOIN %s%s", chname, CRLF);
}
