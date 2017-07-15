/*
** join.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed May 31 16:50:21 2017 Dylan Deu
** Last update Wed May 31 16:50:21 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<string.h>
#include		"error.h"
#include		"client.h"

static void		add_channel(t_client *client, char *name)
{
  unsigned int		index;

  index = 0;
  while (client->channels[index])
    index++;
  client->channels[index] = strdup(name);
}

static void		print_join(t_client *client, t_client *current,
				      char *channel)
{
  t_client		*tmp;

  tmp = client;
  while (tmp)
  {
    if ((find_channel(tmp->channels, channel) == TRUE) && tmp->type == CLIENT)
    {
      dprintf(tmp->fd, ":%s JOIN %s :join channel %s\r\n",
	      current->nickname, channel, channel);
    }
    tmp = tmp->next;
  }
}

void			join(t_client *client, t_client *current)
{
  char			*channel;

  channel = strtok(NULL, " ");
  if (channel == NULL)
    display_error(current->fd, 461, NULL);
  else if (strlen(channel) > CHNAME_MAX_LENGTH)
    display_error(current->fd, 473, channel);
  else
  {
    if (channel[0] != '#' && channel[0] != '&')
    {
      dprintf(current->fd, "432 * %s :Erroneus channel\r\n", channel);
      return ;
    }
    if (nb_channel(current->channels) > MAX_CHANNEL)
    {
      display_error(current->fd, 405, channel);
      return ;
    }
    if (find_channel(current->channels, channel) == FALSE)
      add_channel(current, channel);
    if (find_channel(client->channels, channel) == FALSE)
      add_channel(client, channel);
  }
  print_join(client, current, channel);
}
