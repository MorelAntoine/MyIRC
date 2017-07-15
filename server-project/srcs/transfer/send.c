/*
** send.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/transfer
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Tue May 30 01:37:37 2017 DESKTOP-DHNB9O5
** Last update Tue May 30 02:14:13 2017 DESKTOP-DHNB9O5
*/

#include		<string.h>
#include		<unistd.h>
#include		"transfer.h"

bool			socket_send(int fd, const char *data)
{
  char			buff[BUFF_SIZE];
  int			ret;
  unsigned int		count;

  count = 0;
  while (count < strlen(data))
    {
      memset(buff, '\0', BUFF_SIZE);
      if (strlen(data) - count < BUFF_SIZE - 1)
	{
	  memcpy(buff, data + count, strlen(data) - count);
	  ret = write(fd, buff, strlen(data) - count);
	}
      else
	{
	  memcpy(buff, data + count, BUFF_SIZE - 1);
	  ret = write(fd, buff, BUFF_SIZE - 1);
	}
      if (ret == -1)
	return (FALSE);
      count += ret;
    }
  ret = write(fd, CRLF, 2);
  return (TRUE);
}
