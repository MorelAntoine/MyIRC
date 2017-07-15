/*
** tab.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed Jun 07 15:55:51 2017 Dylan Deu
** Last update Wed Jun 07 15:55:51 2017 Dylan Deu
*/

#include		<string.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<unistd.h>

static int		get_tab_size(char *cmd)
{
  int			index;
  int			size;

  index = 0;
  size = 0;
  while (cmd[index])
  {
    if (cmd[index] == '\r')
      size += 1;
    index++;
  }
  return (size);
}

char			**fill_tab(char *cmd)
{
  int			index;
  int			size;
  char			**new_tab;

  index = 1;
  size = get_tab_size(cmd);
  new_tab = malloc(sizeof(char *) * (size + 1));
  if (new_tab == NULL)
  {
    fprintf(stderr, "Error: Malloc fail\n");
    exit(EXIT_FAILURE);
  }
  new_tab[0] = strtok(cmd, "\r\n");
  while (index < size)
  {
    new_tab[index] = strtok(NULL, "\r\n");
    index++;
  }
  new_tab[index] = NULL;
  return (new_tab);
}
