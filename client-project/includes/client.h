/*
** client.h for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 24 11:18:49 2017 DESKTOP-DHNB9O5
** Last update Wed Jun  7 18:05:47 2017 DESKTOP-DHNB9O5
*/

#ifndef				CLIENT_H_
# define			CLIENT_H_

/*
** DEFINES
*/

# ifndef			EXIT_SUCCESS
#  define			EXIT_SUCCESS 0
# endif				/* !EXIT_SUCCESS */

# ifndef			EXIT_FAILURE
#  define			EXIT_FAILURE 84
# endif				/* !EXIT_FAILURE */

# ifndef			LIMIT_CHANNEL_BY_USER
#  define			LIMIT_CHANNEL_BY_USER 10
# endif				/* !LIMIT_CHANNEL_BY_USER */

# ifndef			MSG_MAX_LENGTH
#  define			MSG_MAX_LENGTH 510
# endif				/* !MSG_MAX_LENGTH */

# ifndef			SPACE
#  define			SPACE " "
# endif				/* !SPACE */

# ifndef			SPECIAL_CHAR
#  define			SPECIAL_CHAR "-[]\`^{}"
# endif				/* !SPECIAL_CHAR */

# ifndef			USERNAME_MAX_LENGTH
#  define			USERNAME_MAX_LENGTH 9
# endif				/* !USERNAME_MAX_LENGTH */

/*
** INCLUDES
*/

# include			"socket.h"
# include			"circular_buffer.h"

/*
** STRUCTURE
*/

typedef struct			s_config
{
  bool				logout;
  t_socket			ssock;
  t_buff			*std_input;
  t_buff			*srv_input;
  char				*nickname;
  char				*channels[10];
  int				current_ch;
}				t_config;

#endif				/* !CLIENT_H_ */
