/*
** display.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project/srcs/error
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 24 17:21:07 2017 DESKTOP-DHNB9O5
** Last update Thu Jun  1 17:34:22 2017 DESKTOP-DHNB9O5
*/

#include			<stdio.h>
#include			"error.h"

static const t_error_msg	error_msg[] =
  {
    { 401, "401 No such nick/channel." },
    { 402, "402 No such server." },
    { 403, "403 No such channel" },
    { 404, "404 Cannot send to channel." },
    { 405, "405 You have joined too many channel." },
    { 411, "411 No recipient given." },
    { 412, "412 No text to send" },
    { 431, "431 No nickname given." },
    { 432, "432 Erroneus nickname." },
    { 433, "433 Nickname is already in use." },
    { 436, "436 Nickname collision KILL." },
    { 442, "442 You're not on that channel." },
    { 446, "446 USERS has been disabled." },
    { 461, "461 Not enough parameters" },
    { 462, "462 You may not reregister." },
    { 471, "471 Cannot join channel (full)." },
    { 473, "473 Cannot join channel." },
    { 474, "474 Cannot join channel (banned)." },
    { 475, "475 Cannot join channel (wrong key)." },
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
      if (data)
	dprintf(input, "%s :", data);
      dprintf(input, "%s%s", error_msg[index].text, CRLF);
    }
  else
    dprintf(input, "Unknown error.%s", CRLF);
}
