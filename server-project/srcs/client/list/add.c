/*
** add.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/srcs/client/list
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Mon May 29 23:20:34 2017 DESKTOP-DHNB9O5
** Last update Tue May 30 00:22:19 2017 DESKTOP-DHNB9O5
*/

#include		"client.h"

void			add_client(t_client *client, t_client *new_client)
{
  t_client		*tmp;

  tmp = client;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new_client;
}
