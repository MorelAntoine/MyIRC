/*
** list.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Thu Jun 01 13:27:49 2017 Dylan Deu
** Last update Thu Jun 01 13:27:49 2017 Dylan Deu
*/

#include		"client.h"

unsigned int		nb_client(t_client *client)
{
  t_client		*tmp;
  unsigned int		size;

  size = 0;
  tmp = client;
  while (tmp)
  {
    size += 1;
    tmp = tmp->next;
  }
  return (size);
}

unsigned int		nb_channel(char **channel)
{
  unsigned int		index;

  index = 0;
  while (channel[index])
    index++;
  return (index);
}
