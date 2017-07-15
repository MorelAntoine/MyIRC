##
## Makefile for myirc in /mnt/d/Projects/C/PSU_2016_myirc/client-project
## 
## Made by DESKTOP-DHNB9O5
## Login   <antoine.morel@epitech.eu>
## 
## Started on  Wed May 24 11:19:03 2017 DESKTOP-DHNB9O5
## Last update Sun Jun 11 19:05:59 2017 DESKTOP-DHNB9O5
##

NAME			=	../client

SRCS			=	srcs/main.c				\
				srcs/answer/dispatcher.c		\
				srcs/answer/channel/join.c		\
				srcs/answer/channel/part.c		\
				srcs/answer/server/nick.c		\
				srcs/cmd/dispatcher.c			\
				srcs/cmd/channel/join.c			\
				srcs/cmd/channel/list.c			\
				srcs/cmd/channel/names.c		\
				srcs/cmd/channel/part.c			\
				srcs/cmd/file_transfer/accept_file.c	\
				srcs/cmd/file_transfer/send_file.c	\
				srcs/cmd/message/send_msg_all.c		\
				srcs/cmd/message/send_msg_to.c		\
				srcs/cmd/server/nick.c			\
				srcs/cmd/server/server.c		\
				srcs/cmd/server/quit.c			\
				srcs/cmd/server/users.c			\
				srcs/error/display.c			\
				srcs/socket/create.c			\
				srcs/socket/connect.c			\
				srcs/core.c				\
				srcs/tab.c				\
				../circular-buffer/buff_read.c		\
				../circular-buffer/buff_write.c		\
				../circular-buffer/get_free_size.c	\
				../circular-buffer/init_buffer.c	\
				../circular-buffer/is_end_cmd.c

OBJS			=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS			=	-W -Wall -Wextra

CFLAGS			+=	-I ./includes/ -I ../circular-buffer/

RM			=	rm -rf

all			:	$(NAME)

$(NAME)			:	$(OBJS)
				$(CC) -o $(NAME) $(OBJS)

clean			:
				$(RM) $(OBJS)

fclean			:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY			:	all clean fclean re
