/*
** circular_buffer.h for irc in /home/dylan/Documents/TEK2/PSU_2016_myirc/circular-buffer
** 
** Made by Dylan Deu
** Login   <dylan.deu@epitech.eu>
** 
** Started on  Tue May 30 16:47:04 2017 Dylan Deu
** Last update Tue May 30 16:52:03 2017 Dylan Deu
*/

#ifndef			CIRCULAR_BUFFER_
# define		CIRCULAR_BUFFER_

#include		<stddef.h>
#include		"bool.h"

#ifndef			BUFF_SIZE
# define		BUFF_SIZE 2048
#endif			/* !BUFF_SIZE */

typedef struct		s_buff
{
  char			buf[2048];
  int			ird;
  int			iwr;
}			t_buff;

t_buff			*init_buff();

void			clean_buff(t_buff *buff);
void			buff_write(t_buff *buff, char *str);

char			*buff_read(t_buff *buf);

size_t			get_free_size(t_buff *buff);
size_t			get_read_size(t_buff *buff);

bool			is_crlf(t_buff *buff);
bool			is_lf(t_buff *buff);

#endif			/* !CIRCULAR_BUFFER_ */
