/*
** server.h for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/includes
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 24 11:24:55 2017 DESKTOP-DHNB9O5
** Last update Tue May 30 00:20:14 2017 DESKTOP-DHNB9O5
*/

#ifndef				SERVER_H_
# define			SERVER_H_

/*
** INCLUDE
*/

# include			"bool.h"

/*
** DEFINES
*/

# ifndef			EXIT_SUCCESS
#  define			EXIT_SUCCESS 0
# endif				/* !EXIT_SUCCESS */

# ifndef			EXIT_FAILURE
#  define			EXIT_FAILURE 84
# endif				/* !EXIT_FAILURE */

/*
** PROTOTYPE
*/

int				g_server_fd;

bool				server(const int port);

#endif				/* !SERVER_H_ */
