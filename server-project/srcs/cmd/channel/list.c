/*
** list.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed May 31 16:51:40 2017 Dylan Deu
** Last update Wed May 31 16:51:40 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<string.h>
#include		"client.h"

void			list(t_client *client, t_client *current)
{
  char			*name;
  unsigned int		index;

  index = 0;
  name = strtok(NULL, " ");
  if (name)
  {
    while (client->channels[index])
    {
      if (strncmp(client->channels[index], name, strlen(name)) == 0)
	dprintf(current->fd, "322 %s %s\r\n", current->nickname,
		client->channels[index]);
      index++;
    }
  }
  else
  {
    while (client->channels[index])
    {
      dprintf(current->fd, "332 %s %s\r\n", current->nickname,
	      client->channels[index]);
      index++;
    }
  }
  dprintf(current->fd, "323 List :End command.\r\n");
}
