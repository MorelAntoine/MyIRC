/*
** buff_write.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Tue May 30 17:20:02 2017 Dylan Deu
** Last update Wed Jun  7 20:25:49 2017 Dylan Deu
*/

#include		"circular_buffer.h"

void			buff_write(t_buff *buff, char *str)
{
  unsigned int		index;

  index = 0;
  while (str[index])
  {
    buff->buf[buff->iwr] = str[index];
    buff->iwr = (buff->iwr + 1) % BUFF_SIZE;
    index++;
  }
}
