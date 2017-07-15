/*
** ask_help.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/srcs/args
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Fri May 26 10:38:21 2017 DESKTOP-DHNB9O5
** Last update Fri May 26 10:40:14 2017 DESKTOP-DHNB9O5
*/

#include		<string.h>
#include		"bool.h"

bool			ask_help(int argc, char **argv)
{
  if (argc != 2)
    return (FALSE);
  if (strcmp(argv[1], "--help") == 0)
    return (TRUE);
  return (FALSE);
}
