/*
** create.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/srcs/client
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Mon May 29 23:14:22 2017 DESKTOP-DHNB9O5
** Last update Tue May 30 00:21:47 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		"socket.h"

static void		init_client(t_client *client)
{
  client->connected = FALSE;
  client->type = CLIENT;
  client->nickname = NULL;
  client->username = NULL;
  client->next = NULL;
}

t_client		*create_client(t_client *server)
{
  struct sockaddr_in	cin;
  socklen_t		socklen;
  t_client		*client;

  socklen = sizeof((cin));
  client = malloc(sizeof(t_client));
  if (client == NULL)
    {
      fprintf(stderr, "Error: Malloc fail\n");
      exit(1);
    }
  client->fd = accept(server->fd, (struct sockaddr *)(&cin), &socklen);
  if (client->fd == -1)
    {
      fprintf(stderr, "Error: Accept fail\n");
      exit(1);
    }
  client->ip = inet_ntoa(cin.sin_addr);
  client->buf = init_buff();
  init_client(client);
  init_channel(client->channels);
  printf("Connection from : %s\n", client->ip);
  return (client);
}
