/*
** client.h for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/includes
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Mon May 29 23:59:27 2017 DESKTOP-DHNB9O5
** Last update Tue May 30 00:20:38 2017 DESKTOP-DHNB9O5
*/

#ifndef				CLIENT_H_
# define			CLIENT_H_

#include			"circular_buffer.h"
#include			"channel.h"

/*
** DEFINES
*/

# ifndef			SERVER
#  define			SERVER 1
# endif				/* !SERVER */

# ifndef			CLIENT
#  define			CLIENT 2
# endif				/* !CLIENT */

/*
** STRUCTURE
*/

typedef struct			s_client
{
  char				connected;
  int				fd;
  char				*ip;
  int				type;
  char				*username;
  char				*nickname;
  char				*current_channel;
  t_buff			*buf;
  char				*channels[MAX_CHANNEL];
  struct s_client		*next;
}				t_client;

/*
** PROTOTYPES
*/

unsigned int			nb_client(t_client *client);
t_client			*create_client(t_client *server);
t_client			*delete_client(t_client *client, int fd);
void				check_connected(t_client *client);
void				add_client(t_client *client, t_client *new_client);

#endif				/* !CLIENT_H_ */
