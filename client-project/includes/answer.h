/*
** answer.h for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/includes
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Thu Jun  1 15:16:42 2017 DESKTOP-DHNB9O5
** Last update Thu Jun  1 19:03:22 2017 DESKTOP-DHNB9O5
*/

#ifndef				ANSWER_H_
# define			ANSWER_H_

/*
** INCLUDE
*/

# include			"client.h"

/*
** PROTOTYPES
*/

void				answer_dispatcher(const char * const token,
						  t_config *config);
void				reset_nick(t_config *config);
void				set_nick(t_config *config);
void				add_channel(t_config *config);
void				exit_channel(t_config *config);

#endif				/* !ANSWER_H_ */
