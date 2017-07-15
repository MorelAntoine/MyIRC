/*
** part.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed May 31 16:53:20 2017 Dylan Deu
** Last update Wed May 31 16:53:20 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<string.h>
#include		"client.h"
#include		"error.h"

static bool		find_other_user(t_client *client, t_client *current,
					   char *name)
{
  t_client		*tmp_client;
  unsigned int		index;

  tmp_client = client;
  while (tmp_client)
  {
    if (tmp_client->type == CLIENT)
    {
      index = 0;
      while (tmp_client->channels[index])
      {
	if (strcmp(tmp_client->channels[index], name) == 0
	    && tmp_client->fd != current->fd)
	  return (TRUE);
	index++;
      }
    }
    tmp_client = tmp_client->next;
  }
  return (FALSE);
}

static void		print_part_all(t_client *client, t_client *current,
					  char *name)
{
  t_client		*tmp_client;
  unsigned int		index;

  tmp_client = client;
  while (tmp_client)
  {
    if (tmp_client->type == CLIENT)
    {
      index = 0;
      while (tmp_client->channels[index])
      {
	if (strcmp(tmp_client->channels[index], name) == 0)
	  dprintf(tmp_client->fd, ":%s PART %s :Part\r\n",
		  current->nickname, name);
	index++;
      }
    }
    tmp_client = tmp_client->next;
  }
}

void			part(t_client *client, t_client *current)
{
  char			*name;

  name = strtok(NULL, " ");
  if (name == NULL)
    dprintf(current->fd, "461 * PART :Not enough parameter\r\n");
  else if (find_channel(current->channels, name) == FALSE)
    dprintf(current->fd, "403 %s %s :No such channel\r\n",
	    current->nickname, name);
  else
  {
    if (find_other_user(client, current, name) == TRUE)
      print_part_all(client, current, name);
    else
    {
      dprintf(current->fd, ":%s PART %s :Part\r\n", current->nickname, name);
      delete_channel(client->channels, name);
    }
    delete_channel(current->channels, name);
  }
}
