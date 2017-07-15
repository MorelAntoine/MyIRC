/*
** error.h for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Fri May 26 16:15:58 2017 DESKTOP-DHNB9O5
** Last update Fri May 26 16:16:00 2017 DESKTOP-DHNB9O5
*/

#ifndef				ERROR_H_
# define			ERROR_H_

/*
** INCLUDE
*/

# include			<stdlib.h>
# include			"socket.h"

/*
** STRUCTURE
*/

typedef struct			s_error_msg
{
  size_t			code;
  char				*text;
}				t_error_msg;

/*
** PROTOTYPE
*/

void				display_error(const t_socket input,
					      const size_t code,
					      const char * const data);

#endif				/* !ERROR_H_ */
