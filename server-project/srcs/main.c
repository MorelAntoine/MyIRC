/*
** main.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 24 11:25:33 2017 DESKTOP-DHNB9O5
** Last update Fri May 26 10:46:07 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<signal.h>
#include		<unistd.h>
#include		"args.h"
#include		"server.h"

static void		sighandler(int sig)
{
  (void)sig;
  close(g_server_fd);
}

static void		display_usage(const char * const binary_name)
{
  printf("USAGE: %s port\n", binary_name);
}

int			main(int argc, char **argv)
{
  int			port;

  signal(SIGINT, sighandler);
  if (ask_help(argc, argv))
    {
      display_usage(argv[0]);
      return (EXIT_SUCCESS);
    }
  if (!check_args(argc, argv))
    {
      display_usage(argv[0]);
      return (EXIT_FAILURE);
    }
  port = atoi(argv[1]);
  if (!server(port))
    return (EXIT_SUCCESS);
  return (EXIT_SUCCESS);
}
