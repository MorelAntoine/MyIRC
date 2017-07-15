/*
** nick.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/cmd/server
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Tue May 30 17:34:16 2017 DESKTOP-DHNB9O5
** Last update Thu Jun  1 17:49:58 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		<string.h>
#include		"client.h"
#include		"error.h"

void			nick(t_config *config)
{
  char			*nick;

  nick = strtok(NULL, SPACE);
  if (!nick)
    {
      display_error(1, 461, NULL);
      return ;
    }
  dprintf(config->ssock, "NICK %s%s", nick, CRLF);
  if (!config->nickname)
    dprintf(config->ssock, "USER Anonymous unknown unknown :dylan\r\n");
}
