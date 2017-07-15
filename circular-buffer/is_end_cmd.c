/*
** is_end_cmd.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Tue May 30 20:28:03 2017 Dylan Deu
** Last update Tue May 30 20:28:03 2017 Dylan Deu
*/

#include		"circular_buffer.h"

bool			is_crlf(t_buff *buff)
{
  int			pos;

  pos = buff->iwr - 1;
  if (pos < 0)
    pos = BUFF_SIZE - 1;
  if (buff->buf[pos] == '\n')
  {
    pos -= 1;
    if (pos < 0)
      pos = BUFF_SIZE - 1;
    if (buff->buf[pos] == '\r')
      return (TRUE);
  }
  return (FALSE);
}

bool			is_lf(t_buff *buff)
{
  int			pos;

  pos = buff->iwr - 1;
  if (pos < 0)
    pos = BUFF_SIZE - 1;
  if (buff->buf[pos] == '\n')
  {
    return (TRUE);
  }
  return (FALSE);
}
