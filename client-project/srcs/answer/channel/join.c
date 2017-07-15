/*
** join.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/answer/channel
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Thu Jun  1 18:35:49 2017 DESKTOP-DHNB9O5
** Last update Wed Jun  7 16:22:07 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		<string.h>
#include		"client.h"
#include		"error.h"

void			add_channel(t_config *config)
{
  char			*chname;
  unsigned int		index;

  chname = strtok(NULL, SPACE);
  if (!chname)
    return ;
  index = 0;
  while (config->channels[index] && index < 10)
    index++;
  if (index == 10)
    {
      display_error(1, 405, NULL);
      return ;
    }
  config->current_ch = index;
  config->channels[index] = strdup(chname);
  if (!config->channels[index])
    exit(EXIT_FAILURE);
  printf("%s has joined %s\n", config->nickname, chname);
}
