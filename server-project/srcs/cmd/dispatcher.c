/*
** dispatcher.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed May 31 15:47:05 2017 Dylan Deu
** Last update Wed May 31 16:41:07 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		<string.h>
#include		"client.h"
#include		"cmd.h"
#include		"error.h"

static const t_cmd	cmds[] =
  {
    { "QUIT", &quit },
    { "NICK", &nick },
    { "USER", &user },
    { "LIST", &list },
    { "JOIN", &join },
    { "PART", &part },
    { "USERS", &users },
    { "NAMES", &names },
    { "PRIVMSG", &send_msg },
    { "/accept_file", &accept_file },
    { NULL, NULL }
  };

void			dispatcher(const char * const token,
				   t_client *client, t_client *current)
{
  unsigned int		index;

  index = 0;
  while (cmds[index].func)
    {
      if (strcmp(token, cmds[index].name) == 0)
	break;
      index++;
    }
  if (cmds[index].func)
    cmds[index].func(client, current);
  else
  {
    display_error(current->fd, 421, token);
  }
}
