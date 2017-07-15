/*
** display.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/srcs/error
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 24 17:21:07 2017 DESKTOP-DHNB9O5
** Last update Wed May 24 17:41:39 2017 DESKTOP-DHNB9O5
*/

#include			<stdio.h>
#include			"error.h"

static const t_error_msg	error_msg[] =
  {
    { 402, "No such server." },
    { 403, "No such channel" },
    { 405, "You have joined too many channel." },
    { 421, "Unknown command." },
    { 431, "No nickname given." },
    { 432, "Erroneus nickname." },
    { 433, "Nickname is already in use." },
    { 436, "Nickname collision KILL." },
    { 442, "You're not on that channel." },
    { 446, "USERS has been disabled." },
    { 461, "Not enough parameters" },
    { 462, "You may not reregister." },
    { 471, "Cannot join channel (full)." },
    { 473, "Cannot join channel." },
    { 474, "Cannot join channel (banned)." },
    { 474, "Cannot join channel (wrong key)." },
    { 0, NULL }
  };

void				display_error(const t_socket input,
					      const size_t code,
					      const char * const data)
{
  int				index;

  index = 0;
  while (error_msg[index].text && code != error_msg[index].code)
    index++;
  if (error_msg[index].text)
    {
      dprintf(input, "%ld ", error_msg[index].code);
      if (data)
	dprintf(input, "%s ", data);
      dprintf(input, ":%s%s", error_msg[index].text, CRLF);
    }
  else
    dprintf(input, "Unknown error.%s", CRLF);
}
