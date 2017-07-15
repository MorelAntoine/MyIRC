/*
** send_msg_all.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Thu Jun 01 11:40:00 2017 Dylan Deu
** Last update Thu Jun 01 11:40:00 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<string.h>
#include		"client.h"
#include		"error.h"

void			send_message_all(t_client *client, t_client *current,
					     char *name)
{
  t_client		*tmp;
  char			*msg;

  msg = strtok(NULL, "\0");
  if (msg == NULL)
    dprintf(current->fd, "461 %s PRIVMSG :Not enough parameters\r\n",
	    current->nickname);
  else
  {
    tmp = client;
    while (tmp)
    {
      if (tmp->type == CLIENT)
      {
	if (find_channel(tmp->channels, name) == TRUE
	    && tmp->fd != current->fd)
	  dprintf(tmp->fd, ":%s PRIVMSG %s %s\r\n", current->nickname,
		  name, msg);
      }
      tmp = tmp->next;
    }
  }
}
