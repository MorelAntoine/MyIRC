/*
** cmd.h for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/includes
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Thu May 25 11:31:37 2017 DESKTOP-DHNB9O5
** Last update Wed May 31 16:39:58 2017 DESKTOP-DHNB9O5
*/

#ifndef				CMD_H_
# define			CMD_H_

/*
** INCLUDES
*/

# include			"bool.h"
#include			"client.h"

typedef struct			s_cmd
{
  char				*name;
  void				(*func)(t_client *client, t_client *current);
}				t_cmd;

/*
** PROTOTYPES
*/

char				**fill_tab(char *cmd);
void				dispatcher(const char * const token,
					   t_client *client,
					       t_client *current);
void				nick(t_client *client, t_client *current);
void				user(t_client *client, t_client *current);
void				quit(t_client *client, t_client *current);
void				list(t_client *client, t_client *current);
void				join(t_client *client, t_client *current);
void				part(t_client *client, t_client *current);
void				users(t_client *client, t_client *current);
void				names(t_client *client, t_client *current);
void				send_msg_to(t_client *client,
						t_client *current, char *name);
void				send_message_all(t_client *client,
						     t_client *current,
						     char *name);
void				send_msg(t_client *client,
						 t_client *current);
void				accept_file(t_client *client,
						t_client *current);

#endif				/* !CMD_H_ */
