/*
** core.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/srcs
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Fri May 26 10:50:40 2017 DESKTOP-DHNB9O5
** Last update Tue May 30 09:20:16 2017 Dylan Deu
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<sys/param.h>
#include		<string.h>
#include		"socket.h"
#include		"error.h"
#include		"transfer.h"
#include		"cmd.h"

static bool		exec_cmd(t_client *client, t_client *tmp,
				    char **new_cmd)
{
  bool			disconnection;
  unsigned int		index;
  char			*token;

  index = 0;
  disconnection = FALSE;
  while (new_cmd[index])
  {
    token = strtok(new_cmd[index], " ");
    if (token == NULL)
    {
      display_error(tmp->fd, 421, NULL);
      return (FALSE);
    }
    if (token[0] == ':')
      token = strtok(NULL, " ");
    if (strcmp(token, "QUIT") == 0)
      disconnection = TRUE;
    dispatcher(token, client, tmp);
    index++;
  }
  return (disconnection);
}

static void		get_cmd(t_client *client, t_client *tmp, char *cmd)
{
  bool			disconnection;
  char			*str;
  char			**new_cmd;

  disconnection = FALSE;
  buff_write(tmp->buf, cmd);
  if (is_crlf(tmp->buf) == TRUE)
  {
    str = buff_read(tmp->buf);
    new_cmd = fill_tab(str);
    disconnection = exec_cmd(client, tmp, new_cmd);
    if (str)
      free(str);
    if (new_cmd != NULL)
      free(new_cmd);
  }
  if (tmp->connected == FALSE && tmp->type == CLIENT &&
      disconnection == FALSE)
    check_connected(tmp);
}

static void		run(t_client *client, fd_set *fd_read)
{
  t_client		*tmp;
  t_client		*new;
  size_t		read_size;
  char			cmd[BUFF_SIZE];

  tmp = client;
  memset(cmd, 0, BUFF_SIZE);
  while (tmp)
    {
      if (FD_ISSET(tmp->fd, fd_read) && tmp->type == SERVER)
	{
	  new = create_client(tmp);
	  add_client(client, new);
	}
      else if (FD_ISSET(tmp->fd, fd_read) && tmp->type == CLIENT)
	{
	  read_size = get_free_size(tmp->buf);
	  if (read(tmp->fd, cmd, read_size) <= 0)
	    tmp = delete_client(client, tmp->fd);
	  else
	    get_cmd(client, tmp, cmd);
	}
      tmp = tmp->next;
    }
}

static bool		initialize(t_client *server, const int port)
{
  server->fd = create_socket("TCP");
  if (server->fd == SOCKET_ERROR)
    {
      perror("initialize : create_socket()");
      return (FALSE);
    }
  g_server_fd = server->fd;
  if (!socket_bind(server->fd, INADDR_ANY, htons(port), server))
    {
      perror("initialize : socket_bind()");
      close_socket(server->fd);
      return (FALSE);
    }
  if (!socket_listen(server->fd, LISTEN_LIMIT))
    {
      perror("initialize : socket_listen()");
      close_socket(server->fd);
      return (FALSE);
    }
  server->type = SERVER;
  server->username = NULL;
  server->next = NULL;
  server->nickname = NULL;
  server->buf = NULL;
  return (init_channel(server->channels));
}

bool			server(const int port)
{
  t_client		*client;
  fd_set		fd_write;
  fd_set		fd_read;

  client = malloc(sizeof(t_client));
  if (client == NULL)
    {
      perror("server : malloc()\n");
      return (FALSE);
    }
  if (!initialize(client, port))
    {
      free(client);
      return (FALSE);
    }
  while (make_select(client, &fd_read, &fd_write) != -1)
    run(client, &fd_read);
  if (client->buf)
    free(client->buf);
  if (client)
    free(client);
  return (FALSE);
}
