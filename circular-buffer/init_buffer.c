/*
** init_buffer.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Tue May 30 17:08:49 2017 Dylan Deu
** Last update Tue May 30 17:08:49 2017 Dylan Deu
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>
#include		"circular_buffer.h"

t_buff			*init_buff()
{
  t_buff		*buf;

  buf = malloc(sizeof(t_buff));
  if (buf == NULL)
  {
    fprintf(stderr, "Error: Malloc fail\n");
    exit(EXIT_FAILURE);
  }
  memset(buf->buf, 0, BUFF_SIZE);
  buf->ird = 0;
  buf->iwr = 0;
  return (buf);
}

void			clean_buff(t_buff *buff)
{
  memset(buff->buf, 0, BUFF_SIZE);
}
