/*
** quit.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/cmd/server
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Fri May 26 15:14:50 2017 DESKTOP-DHNB9O5
** Last update Thu Jun  1 15:29:06 2017 DESKTOP-DHNB9O5
*/

#include		"client.h"

void			quit(t_config *config)
{
  config->logout = TRUE;
  if (config->ssock != SOCKET_ERROR)
    close_socket(config->ssock);
}
