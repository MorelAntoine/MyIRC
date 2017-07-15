/*
** nick.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/answer/server
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Thu Jun  1 15:14:45 2017 DESKTOP-DHNB9O5
** Last update Thu Jun  1 16:11:12 2017 DESKTOP-DHNB9O5
*/

#include		<string.h>
#include		<stdio.h>
#include		<malloc.h>
#include		"client.h"

void			reset_nick(t_config *config)
{
  char			*nick;

  nick = strtok(NULL, SPACE);
  if (!nick)
    return ;
  if (config->nickname)
    free(config->nickname);
  config->nickname = strdup(nick + 1);
  printf("reset nick ok: %s\n", config->nickname);
}

void			set_nick(t_config *config)
{
  char			*nick;

  nick = strtok(NULL, SPACE);
  if (config->nickname)
    free(config->nickname);
  config->nickname = strdup(nick);
  printf("set nick ok: %s\n", config->nickname);
}
