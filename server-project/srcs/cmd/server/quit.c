/*
** quit.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed May 31 16:59:14 2017 Dylan Deu
** Last update Wed May 31 16:59:14 2017 Dylan Deu
*/

#include		<stdio.h>
#include		"client.h"

void			quit(t_client *client, t_client *current)
{
  dprintf(current->fd, "QUIT :See you later %s%s", current->nickname, "\r\n");
  client = delete_client(client, current->fd);
}
