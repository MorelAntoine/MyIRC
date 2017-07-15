/*
** channel.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Thu Jun 01 17:53:01 2017 Dylan Deu
** Last update Thu Jun 01 17:53:01 2017 Dylan Deu
*/

#include	<string.h>
#include	<stdlib.h>
#include <client.h>
#include	"channel.h"

bool		init_channel(char **channel)
{
  unsigned int	index;

  index = 0;
  while (index < MAX_CHANNEL)
  {
    channel[index] = NULL;
    index++;
  }
  return (TRUE);
}

bool		find_channel(char **channel, char *name)
{
  unsigned int	index;

  index = 0;
  while (channel[index])
  {
    if (strcmp(channel[index], name) == 0)
      return (TRUE);
    index++;
  }
  return (FALSE);
}

void		delete_channel(char **channel, char *name)
{
  unsigned int	index;

  index = 0;
  while (channel[index])
  {
    if (strcmp(channel[index], name) == 0)
    {
      free(channel[index]);
      while (channel[index + 1])
      {
	channel[index] = channel[index + 1];
	index++;
      }
      channel[index] = NULL;
      break;
    }
    index++;
  }
}
