/*
** receive.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/srcs/transfer
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Tue May 30 00:30:16 2017 DESKTOP-DHNB9O5
** Last update Tue May 30 01:47:58 2017 DESKTOP-DHNB9O5
*/

#include		<stdlib.h>
#include		<string.h>
#include		<unistd.h>
#include		"server.h"
#include		"transfer.h"

static void		set_end_packed(char *str, char *buff, const int length)
{
  if (length == 1 && buff[0] == CR && buff[1] == LF)
    return ;
  else if (length > 1)
    {
      str = realloc(str, strlen(str) + length - 2 + 1);
      str[strlen(str) + length - 2] = '\0';
      memcpy(str + strlen(str), buff, length - 2);
    }
  else
    str[strlen(str) - 1] = '\0';
}

static bool		is_end_packed(char *str, char *buff, const int length)
{
  if (length > 1)
    {
      if (buff[length - 2] == CR && buff[length - 1] == LF)
	return (TRUE);
    }
  else if (strlen(str) > 0)
    {
      if (str[strlen(str) - 1] == CR && buff[0] == LF)
	return (TRUE);
    }
  return (FALSE);
}

char			*socket_receive(int fd)
{
  char			buff[BUFF_SIZE];
  int			ret;
  char			*str;

  str = malloc(1);
  if (!str)
    exit(EXIT_FAILURE);
  str[0] = '\0';
  while (2)
    {
      memset(buff, '\0', BUFF_SIZE);
      ret = read(fd, buff, BUFF_SIZE - 1);
      if (ret == -1 || ret == 0)
	return (NULL);
      if (is_end_packed(str, buff, ret))
	{
	  set_end_packed(str, buff, ret);
	  break;
	}
      str = realloc(str, strlen(str) + ret + 1);
      str[strlen(str) + ret] = '\0';
      memcpy(str + strlen(str), buff, ret);
    }
  return (str);
}
