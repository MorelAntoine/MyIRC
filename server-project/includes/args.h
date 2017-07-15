/*
** args.h for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/includes
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Fri May 26 10:31:47 2017 DESKTOP-DHNB9O5
** Last update Fri May 26 10:33:26 2017 DESKTOP-DHNB9O5
*/

#ifndef				ARGS_H_
# define			ARGS_H_

/*
** INCLUDE
*/

# include			"bool.h"

/*
** PROTOTYPES
*/

bool				ask_help(int argc, char **argv);
bool				check_args(int args, char **argv);

#endif				/* !ARGS_H_ */
