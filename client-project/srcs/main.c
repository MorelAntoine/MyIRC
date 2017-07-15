/*
** main.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 24 11:19:17 2017 DESKTOP-DHNB9O5
** Last update Sun Jun 11 18:50:11 2017 DESKTOP-DHNB9O5
*/

#include		<malloc.h>
#include		<signal.h>
#include		<string.h>
#include		<sys/param.h>
#include		"client.h"
#include		"cmd.h"

bool			config_logout;

static void		sighandler(int sig)
{
  (void)sig;
  config_logout = TRUE;
}


static int		prepare_select(t_socket ssock, fd_set *fd_read)
{
  struct timeval	time;
  int			max;

  max = 1;
  time.tv_usec = 0;
  time.tv_sec = 5;
  FD_ZERO(fd_read);
  FD_SET(0, fd_read);
  if (ssock > 0)
    FD_SET(ssock, fd_read);
  if (ssock > 0 && ssock > max)
    max = ssock + 1;
  if (select(max, fd_read, NULL, NULL, &time) == -1)
    {
      perror("prepare_select : select()");
      return (-1);
    }
  return (0);
}

static void		set_config(t_config *config)
{
  int			index;

  config->srv_input = init_buff();
  config->std_input = init_buff();
  config->logout = FALSE;
  config->ssock = SOCKET_ERROR;
  config->nickname = NULL;
  config->current_ch = -1;
  index = 0;
  while (index < 10)
    {
      config->channels[index] = NULL;
      index++;
    }
}

int			main(void)
{
  fd_set		fd_read;
  t_config		config;
  static bool		prompt = 1;

  signal(SIGINT, sighandler);
  config_logout = FALSE;
  set_config(&config);
  while (!config.logout)
    {
      config.logout = config_logout;
      if (prompt)
	{
	  if (config.nickname != NULL)
	    dprintf(1, "%s@irc $> ", config.nickname);
	  else
	    dprintf(1, "$> ");
	  prompt = FALSE;
	}
      if (prepare_select(config.ssock, &fd_read) != -1)
	run(&config, &fd_read, &prompt);
      else
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
