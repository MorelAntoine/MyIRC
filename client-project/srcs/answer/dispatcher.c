/*
** dispatcher.c for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project/srcs/answer
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Thu Jun  1 14:53:24 2017 DESKTOP-DHNB9O5
** Last update Sun Jun 11 20:16:21 2017 Dylan Deu
*/

#include		<stdio.h>
#include		<string.h>
#include		"client.h"
#include		"answer.h"

static void		interpret(const char * const token,
				  const char * const cmd)
{
  char			*ch;
  char			*msg;

  if (strcmp(cmd, "PRIVMSG") == 0)
    {
      ch = strtok(NULL, SPACE);
      if (!ch)
	return ;
      msg = strtok(NULL, SPACE);
      printf("[%s] %s : %s", ch + 1, token + 1, msg + 1);
      while ((msg = strtok(NULL, SPACE)))
	printf(" %s", msg);
      printf("\n");
    }
  else if (strcmp(cmd, "PART") == 0 || strcmp(cmd, "JOIN") == 0)
    {
      ch = strtok(NULL, SPACE);
      if (!ch)
	return ;
      if (strcmp(cmd, "PART") == 0)
	printf("%s exit %s\n", token + 1, ch);
      else
	printf("%s join %s\n", token + 1, ch);
    }
}

static void		error_answer(const char * const token,
				     const char * const prev_cmd)
{
  char			*cmd;

  printf("%s %s", token, prev_cmd);
  cmd = strtok(NULL, SPACE);
  while (cmd)
    {
      printf(" %s", cmd);
      cmd = strtok(NULL, SPACE);
    }
  printf("\n");
}

static void		special_answer(const char * const token,
				       t_config * config)
{
  char			*cmd;

  cmd = strtok(NULL, SPACE);
  if (!cmd)
    return ;
  if (strcmp(cmd, "NICK") == 0)
    reset_nick(config);
  else if (strcmp(cmd, "JOIN") == 0
	   && strcmp(config->nickname, token + 1) == 0)
    add_channel(config);
  else if (strcmp(cmd, "PART") == 0
	   && strcmp(config->nickname, token + 1) == 0)
    exit_channel(config);
  else if (token[0] == ':')
    interpret(token, cmd);
  else
    error_answer(token, cmd);
}

void			answer_dispatcher(const char * const token,
					  t_config *config)
{
  if (strcmp(token, "001") == 0)
    set_nick(config);
  else
    special_answer(token,config);
}
