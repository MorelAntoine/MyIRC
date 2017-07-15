/*
** nick.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed May 31 15:54:01 2017 Dylan Deu
** Last update Wed May 31 15:54:01 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<string.h>
#include		"client.h"
#include		"error.h"

static void		print_nick_all(t_client *tmp, t_client *current,
					  unsigned int index, char *nick)
{
  unsigned int		other;

  other = 0;
  while (tmp->channels[other])
  {
    if (strcmp(current->channels[index], tmp->channels[other]) == 0)
    {
      dprintf(tmp->fd, ":%s NICK :%s\r\n", current->nickname,
	      nick);
      break;
    }
    other++;
  }
}

static void		send_msg(t_client *client, t_client *current, char *nick)
{
  t_client		*tmp;
  unsigned int		index;

  tmp = client;
  if (current->channels[0] == NULL)
  {
    dprintf(current->fd, ":%s NICK :%s\r\n", current->nickname,
	    nick);
    return ;
  }
  while (tmp)
  {
    if (tmp->type == CLIENT)
    {
      index = 0;
      while (current->channels[index])
      {
	print_nick_all(tmp, current, index, nick);
	index++;
      }
    }
    tmp = tmp->next;
  }
  free(current->nickname);
}

static void		set_nick(t_client *client, t_client *current,
				    char *nick)
{
  if (current->connected == TRUE)
    send_msg(client, current, nick);
  current->nickname = strdup(nick);
}

void			nick(t_client *client, t_client *current)
{
  t_client		*tmp;
  char			*nick;

  tmp = client;
  nick = strtok(NULL, " ");
  if (nick == NULL)
    display_error(current->fd, 461, "NICK");
  else if (strlen(nick) > 9)
    display_error(current->fd, 432, nick);
  else
  {
    if (current->nickname && strcmp(current->nickname, nick) == 0)
      return ;
    while (tmp)
    {
      if (tmp->nickname != NULL && strcmp(tmp->nickname, nick) == 0)
      {
	display_error(current->fd, 433, nick);
	return ;
      }
      tmp = tmp->next;
    }
    set_nick(client, current, nick);
  }
}
