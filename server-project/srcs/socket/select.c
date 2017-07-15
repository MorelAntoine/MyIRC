/*
** select.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Mon May 29 16:08:10 2017 Dylan Deu
** Last update Tue May 30 00:23:32 2017 DESKTOP-DHNB9O5
*/

#include		<sys/select.h>
#include		<stdio.h>
#include		"client.h"

static int		find_max_fd(t_client *client, fd_set *fd_read,
				    fd_set *fd_write)
{
  int			max;
  t_client 		*tmp;

  tmp = client;
  max = tmp->fd;
  FD_ZERO(fd_read);
  FD_ZERO(fd_write);
  while (tmp != NULL)
    {
      if (tmp->fd > 0)
	{
	  FD_SET(tmp->fd, fd_read);
	  FD_SET(tmp->fd, fd_write);
	  if (tmp->fd > max)
	    max = tmp->fd;
	}
      tmp = tmp->next;
    }
  return (max);
}

int			make_select(t_client *client, fd_set *fd_read,
				    fd_set *fd_write)
{
  struct timeval	time;
  int			max_fd;

  max_fd = find_max_fd(client, fd_read, fd_write);
  time.tv_usec = 0;
  time.tv_sec = 5;
  if (select(max_fd + 1, fd_read, NULL, NULL, &time) == -1)
    {
      perror("make_select : select()");
      return (-1);
    }
  return (0);
}
