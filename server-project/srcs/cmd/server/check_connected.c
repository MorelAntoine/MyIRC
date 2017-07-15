/*
** check_connected.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed May 31 16:41:37 2017 Dylan Deu
** Last update Wed May 31 16:41:37 2017 Dylan Deu
*/

#include		<stdio.h>
#include		"client.h"

#include <unistd.h>

void			check_connected(t_client *current)
{
  if (current->nickname != NULL && current->username != NULL)
  {
    dprintf(current->fd, "001 %s :Welcome %s%s", current->nickname,
	    current->nickname, "\r\n");
    current->connected = TRUE;
  }
}
