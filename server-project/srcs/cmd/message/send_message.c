/*
** send_message.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Thu Jun 01 11:38:40 2017 Dylan Deu
** Last update Thu Jun 01 11:38:40 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<string.h>
#include		"error.h"
#include		"cmd.h"

static bool		find_user(t_client *client, char *name)
{
  t_client		*tmp;

  tmp = client;
  while (tmp)
  {
    if (tmp->type == CLIENT)
    {
      if (strcmp(tmp->nickname, name) == 0)
	return (TRUE);
    }
    tmp = tmp->next;
  }
  return (FALSE);
}

void			send_msg(t_client *client, t_client *current)
{
  char			*name;

  name = strtok(NULL, " ");
  if (name == NULL)
    display_error(current->fd, 461, "PRIVMSG");
  else
  {
    if (find_channel(client->channels, name) == TRUE)
      send_message_all(client, current, name);
    else if (find_user(client, name) == TRUE)
      send_msg_to(client, current, name);
    else
      dprintf(current->fd, "401 PRIVMSG :No such nick/channel\r\n");
  }
}
