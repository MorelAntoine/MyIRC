/*
** buff_read.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Tue May 30 17:26:19 2017 Dylan Deu
** Last update Wed Jun  7 20:25:24 2017 Dylan Deu
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>
#include		"circular_buffer.h"

char			*buff_read(t_buff *buf)
{
  char			*str;
  size_t		index;
  size_t		size_str;

  index = 0;
  size_str = get_read_size(buf);
  str = malloc(sizeof(char) * (size_str + 1));
  if (str == NULL)
  {
    fprintf(stderr, "Error: Malloc fail\n");
    exit(EXIT_FAILURE);
  }
  memset(str, 0, size_str);
  while (index < size_str)
  {
    str[index] = buf->buf[buf->ird];
    buf->ird = (buf->ird + 1) % BUFF_SIZE;
    index++;
  }
  str[index] = '\0';
  return (str);
}
