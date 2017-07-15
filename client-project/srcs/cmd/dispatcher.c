/*
** dispatcher.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/cmd
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Fri May 26 15:00:15 2017 DESKTOP-DHNB9O5
** Last update Thu Jun  1 17:17:17 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		<string.h>
#include		"client.h"
#include		"cmd.h"

static const t_cmd	cmds[] =
  {
    { "/server", &server },
    { "/quit", &quit },
    { "/nick", &nick },
    { "/list", &list },
    { "/join", &join },
    { "/part", &part },
    { "/users", &users },
    { "/names", &names },
    { "/msg", &send_msg_to },
    { "/accept_file", &accept_file },
    { NULL, NULL }
  };

void			dispatcher(const char * const token,
				   t_config *config)
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
    cmds[index].func(config);
  else
    send_msg_all(token, config);
}
