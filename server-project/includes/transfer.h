/*
** transfer.h for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/includes
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Tue May 30 00:57:56 2017 DESKTOP-DHNB9O5
** Last update Tue May 30 01:59:45 2017 DESKTOP-DHNB9O5
*/

#ifndef				TRANSFER_H_
# define			TRANSFER_H_

/*
** INCLUDE
*/

# include			"bool.h"

/*
** DEFINES
*/

# ifndef			BUFF_SIZE
#  define			BUFF_SIZE 512
# endif				/* !BUFF_SIZE */

# ifndef			CR
#  define			CR '\r'
# endif				/* !CR */

# ifndef			LF
#  define			LF '\n'
# endif				/* !LF */

# ifndef			CRLF
#  define			CRLF "\r\n"
# endif				/* !CRLF */

/*
** PROTOTYPES
*/

char				*socket_receive(int fd);
bool				socket_send(int fd, const char *data);

#endif				/* !TRANSFER */
