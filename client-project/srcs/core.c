/*
** core.c for irc in /home/dylan/Documents/TEK2/PSU_2016_myirc/client-project/srcs
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Wed May 31 13:07:17 2017 Dylan Deu
** Last update Sun Jun 11 19:02:52 2017 DESKTOP-DHNB9O5
*/

#include		<sys/param.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<unistd.h>
#include		<string.h>
#include		"answer.h"
#include		"cmd.h"

static int		get_cmd(t_config *client, t_buff *buff, int fd)
{
  char			str[BUFF_SIZE];
  size_t		read_size;

  memset(str, 0, BUFF_SIZE);
  read_size = get_free_size(buff);
  if (read(fd, str, read_size) <= 0)
    {
      quit(client);
      return (-1);
    }
  buff_write(buff, str);
  return (0);
}

static void		treat_standard_cmd(t_config *client,
					   char *str)
{
  int			index;
  char			**cmd;
  char			*token;

  index = 0;
  cmd = fill_tab(str);
  while (cmd[index])
    {
      token = strtok(cmd[index], SPACE);
      if (!token)
	{
	  index++;
	  continue;
	}
      if (token[0] == ':')
	token = strtok(NULL, SPACE);
      if (token)
	dispatcher(token, client);
      index++;
    }
  free_tab(cmd);
}

static void		treat_server_cmd(t_config *client,
					 char *str)
{
  int			index;
  char			**cmd;
  char			*token;

  index = 0;
  cmd = fill_tab(str);
  while (cmd[index])
    {
      token = strtok(cmd[index], SPACE);
      if (token)
	answer_dispatcher(token, client);
      index++;
    }
}

void			run(t_config *client, fd_set *fd_read,
			    bool *prompt)
{
  char			*str;

  if (FD_ISSET(0, fd_read))
    {
      if (get_cmd(client, client->std_input, 0) == -1)
        return ;
      if (is_lf(client->std_input) == TRUE)
	{
	  str = buff_read(client->std_input);
	  treat_standard_cmd(client, str);
	}
      (*prompt) = TRUE;
    }
  if (client->ssock > 0 && FD_ISSET(client->ssock, fd_read))
    {
      if (get_cmd(client, client->srv_input, client->ssock) == -1)
	return ;
      if (is_crlf(client->srv_input) == TRUE)
	{
	  str = buff_read(client->srv_input);
	  treat_server_cmd(client, str);
	}
      (*prompt) = TRUE;
    }
}
