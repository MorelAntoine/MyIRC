/*
** user.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed May 31 16:05:51 2017 Dylan Deu
** Last update Wed May 31 16:05:51 2017 Dylan Deu
*/

#include		<string.h>
#include		"client.h"
#include		"error.h"

void			user(t_client *client, t_client *current)
{
  unsigned int		cpt;

  cpt = 0;
  (void)client;
  while (cpt < 3)
  {
    if (strtok(NULL, " ") == NULL)
      display_error(current->fd, 461, NULL);
    cpt++;
  }
  if (current->connected)
    display_error(current->fd, 462, NULL);
  else
    current->username = strtok(NULL, " ");
  if (current->username == NULL)
    display_error(current->fd, 461, NULL);
}
