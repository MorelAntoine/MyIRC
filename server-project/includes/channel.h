/*
** channel.h for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/includes
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 24 14:02:27 2017 DESKTOP-DHNB9O5
** Last update Wed May 24 14:47:11 2017 DESKTOP-DHNB9O5
*/

#ifndef				CHANNEL_H_
# define			CHANNEL_H_

/*
** INCLUDES
*/

# include			"bool.h"
# include			"server.h"

/*
** DEFINES
*/

/*
** Channels names are strings (beginning with a '&' or '#' character) of
** length up to 200 characters.
** A channel operator is identified by the '@' symbol next to their
** nickname whenever it is associated with a channel.
** only restriction on a channel name is that it may not contain any
** spaces (' '), a control G (^G or ASCII 7), or a comma (',' which
** is used as a list item separator by the protocol).
*/
# ifndef			CHSYM
#  define			CHSYM '&'
# endif				/* !CHANNEL_SYM */

# ifndef			CHNAME_MAX_LENGTH
#  define			CHNAME_MAX_LENGTH 200
# endif				/* !CHNAME_MAX_LENGTH */

# ifndef			MAX_CHANNEL
#  define			MAX_CHANNEL 10
# endif				/* !MAX_CHANNEL */

# ifndef			CHFORBIDDEN_CHAR
#  define			CHFORBIDDEN_CHAR " ^G,"
# endif				/* !CHFORBIDDEN_CHAR */

# ifndef			CHOPERATOR_SYM
#  define			CHOPERATOR_SYM '@'
# endif				/* !CHOPERATOR_SYM */

/*
** STRUCTURES
*/

/*
** If the channel doesn't exist prior to joining, the channel is
** created and the creating user becomes a channel operator.
*/

/*
** PROTOTYPES
*/

unsigned int			nb_channel(char **channel);
bool				find_channel(char **channel, char *name);
bool				init_channel(char **channel);
void				delete_channel(char **channel, char *name);

#endif				/* !CHANNEL_H_ */
