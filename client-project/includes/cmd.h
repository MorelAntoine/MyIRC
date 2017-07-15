/*
** cmd.h for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/includes
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Thu May 25 11:31:37 2017 DESKTOP-DHNB9O5
** Last update Sun Jun 11 18:46:36 2017 DESKTOP-DHNB9O5
*/

#ifndef				CMD_H_
# define			CMD_H_

/*
** INCLUDE
*/

# include			"client.h"

/*
** STRUCTURE
*/

typedef struct			s_cmd
{
  char				*name;
  void				(*func)(t_config *config);
}				t_cmd;

/*
** PROTOTYPES
*/

void				run(t_config *client, fd_set *fd_read, bool *prompt);
void				dispatcher(const char * const token,
					   t_config *config);
void				server(t_config *config);
void				quit(t_config *config);
void				nick(t_config *config);
void				list(t_config *config);
void				join(t_config *config);
void				part(t_config *config);
void				users(t_config *config);
void				names(t_config *config);
void				send_file(t_config *config);
void				accept_file(t_config *config);
void				send_msg_to(t_config *config);
void				send_msg_all(const char * const msg,
					     t_config *config);
void				free_tab(char **tab);
char				**fill_tab(char *cmd);

#endif				/* !CMD_H_ */
