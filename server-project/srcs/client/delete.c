/*
** delete.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/srcs/client
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Tue May 30 00:07:18 2017 DESKTOP-DHNB9O5
** Last update Tue May 30 00:22:02 2017 DESKTOP-DHNB9O5
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		<stdio.h>
#include		"socket.h"

void			free_client(t_client *client)
{
  if (client->buf)
    free(client->buf);
  if (client->nickname)
    free(client->nickname);
}

t_client		*delete_client(t_client *client, int fd)
{
  t_client		*tmp;
  t_client		*head;
  t_client		*del;

  tmp = client;
  head = client;
  while (tmp->next)
    {
      if (tmp->next->fd == fd)
	{
	  del = tmp->next;
	  if (tmp->next->next == NULL)
	    tmp->next = NULL;
	  else
	    tmp->next = tmp->next->next;
	  close(del->fd);
	  free_client(del);
	  free(del);
	  printf("Close connection : %s\n", client->ip);
	  return (client);
	}
      tmp = tmp->next;
    }
  return (head);
}
