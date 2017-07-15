/*
** send_msg_to.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed May 31 16:54:16 2017 Dylan Deu
** Last update Wed May 31 16:54:16 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<string.h>
#include		"client.h"
#include		"error.h"

void			send_msg_to(t_client *client, t_client *current,
					char *name)
{
  t_client		*tmp;
  char			*msg;

  msg = strtok(NULL, "\0");
  if (msg == NULL)
    display_error(current->fd, 461, "PRIVMSG");
  else
  {
    tmp = client;
    while (tmp)
    {
      if (tmp->type != SERVER)
      {
	if (strcmp(tmp->nickname, name) == 0 && tmp->fd != current->fd)
	{
	  dprintf(tmp->fd, ":%s PRIVMSG %s %s\r\n", current->nickname,
		  name, msg);
	  break;
	}
      }
      tmp = tmp->next;
    }
  }
}
