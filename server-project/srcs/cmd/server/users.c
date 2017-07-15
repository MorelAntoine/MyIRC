/*
** users.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed May 31 16:57:05 2017 Dylan Deu
** Last update Wed May 31 16:57:05 2017 Dylan Deu
*/

#include		<stdio.h>
#include		"client.h"

void			users(t_client *client, t_client *current)
{
  t_client		*tmp;

  tmp = client;
  while (tmp)
  {
    if (client->type == CLIENT && client->connected == TRUE)
      dprintf(current->fd, "265 %s %s\r\n", current->nickname, tmp->nickname);
    tmp = tmp->next;
  }
  dprintf(current->fd, "266 %s * :End of USERS\r\n", current->nickname);
}
