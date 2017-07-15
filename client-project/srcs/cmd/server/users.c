/*
** users.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/cmd/server
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Tue May 30 17:34:45 2017 DESKTOP-DHNB9O5
** Last update Thu Jun  1 16:06:01 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		"client.h"
#include		"error.h"

void			users(t_config *config)
{
  if (!config->nickname)
    {
      display_error(1, 431, NULL);
      return ;
    }
  dprintf(config->ssock, "USERS%s", CRLF);
}
