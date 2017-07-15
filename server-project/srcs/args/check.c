/*
** check.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/srcs/args
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Fri May 26 10:40:32 2017 DESKTOP-DHNB9O5
** Last update Fri May 26 10:43:54 2017 DESKTOP-DHNB9O5
*/

#include		<ctype.h>
#include		"bool.h"

static bool		is_number(char *nbr)
{
  unsigned int		index;

  index = 0;
  while (nbr[index] != '\0')
    {
      if (!isdigit(nbr[index]))
	return (FALSE);
      index++;
    }
  return (TRUE);
}

bool			check_args(int argc, char **argv)
{
  if (argc != 2)
    return (FALSE);
  if (!is_number(argv[1]))
    return (FALSE);
  return (TRUE);
}
