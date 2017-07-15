/*
** part.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/answer/channel
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Thu Jun  1 18:42:36 2017 DESKTOP-DHNB9O5
** Last update Wed Jun  7 20:26:42 2017 Dylan Deu
*/

#include		<malloc.h>
#include		<stdio.h>
#include		<string.h>
#include		"client.h"

static void		update_current_channel_index(t_config *config)
{
  unsigned int		index;

  index = 9;
  while (index > 0)
    {
      if (config->channels[index])
	{
	  config->current_ch = index;
	  return ;
	}
      index--;
    }
  config->current_ch = -1;
}

void			exit_channel(t_config *config)
{
  char			*chname;
  int			index;

  chname = strtok(NULL, SPACE);
  if (!chname)
    return ;
  index = 0;
  while (config->channels[index] && index < 10)
    {
      if (strcmp(chname, config->channels[index]) == 0)
	{
	  free(config->channels[index]);
	  if (index == config->current_ch)
	    update_current_channel_index(config);
	  printf("%s exit %s\n", config->nickname, chname);
	  return ;
	}
      index++;
    }
}
