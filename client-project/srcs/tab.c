/*
** tab.c for PSU_2016_myirc in /home/dylan/Documents/TEK2/PSU_2016_myirc
**
** Made by Dylan Deu
** Login   <dylan.deu@epitech.net>
**
** Started on  Wed May 31 20:17:27 2017 Dylan Deu
** Last update Wed Jun  7 18:14:33 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>

static int		get_tab_size(char *cmd)
{
  int			index;
  int			size;

  index = 0;
  size = 0;
  while (cmd[index])
    {
      if (cmd[index] == '\n')
	size += 1;
      index++;
    }
  return (size);
}

void			free_tab(char **tab)
{
  int			index;

  index = 0;
  if (tab == NULL)
    return ;
  while (tab[index])
    {
      free(tab[index]);
      index++;
    }
  free(tab);
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
