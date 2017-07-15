/*
** names.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed May 31 16:52:28 2017 Dylan Deu
** Last update Wed May 31 16:52:28 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<string.h>
#include		"error.h"
#include		"client.h"

static void		name_channel(t_client *client, t_client *current,
					char *name)
{
  t_client		*tmp;

  tmp = client;
  while (tmp)
  {
    if (tmp->type == CLIENT)
    {
      if (find_channel(tmp->channels, name) == TRUE)
	dprintf(current->fd, "265 %s %s\r\n", current->nickname,
		tmp->nickname);
    }
    tmp = tmp->next;
  }
}

void			names(t_client *client, t_client *current)
{
  char			*name;

  name = strtok(NULL, " ");
  if (name == NULL)
    display_error(current->fd, 461, "NAMES");
  else
    name_channel(client, current, name);
  dprintf(current->fd, "266 NAMES :End of list\r\n");
}
