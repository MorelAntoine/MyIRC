/*
** get_free_size.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Tue May 30 17:19:01 2017 Dylan Deu
** Last update Tue May 30 17:19:01 2017 Dylan Deu
*/

#include		"circular_buffer.h"

#include <stdio.h>

size_t			get_free_size(t_buff *buff)
{
  size_t		size;

  if (buff->iwr >= buff->ird)
    size = (size_t)(BUFF_SIZE - (buff->iwr - buff->ird));
  else
    size = (size_t)(buff->ird - buff->iwr);
  return (size);
}

size_t			get_read_size(t_buff *buff)
{
  size_t		size;

  if (buff->ird > buff->iwr)
    size = (size_t)(BUFF_SIZE - (buff->ird - buff->iwr));
  else
    size = (size_t)(buff->iwr - buff->ird);
  return (size);
}
