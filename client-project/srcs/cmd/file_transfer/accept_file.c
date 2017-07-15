/*
** accept_file.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/cmd/file_transfer
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Tue May 30 17:31:40 2017 DESKTOP-DHNB9O5
** Last update Wed Jun  7 18:27:22 2017 DESKTOP-DHNB9O5
*/

#include		<string.h>
#include		<stdio.h>
#include		"client.h"
#include		"error.h"

void			accept_file(t_config *config)
{
  char			*nickname;

  nickname = strtok(NULL, SPACE);
  if (!nickname)
    {
      display_error(config->ssock, 461, NULL);
      return ;
    }
  dprintf(config->ssock, "ACCEPT_FILE %s%s", nickname, CRLF);
}
