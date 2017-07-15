
##
## Makefile for myirc in /mnt/d/Projects/C/PSU_2016_myirc/server-project
## 
## Made by DESKTOP-DHNB9O5
## Login   <antoine.morel@epitech.eu>
## 
## Started on  Wed May 24 11:21:17 2017 DESKTOP-DHNB9O5
## Last update Sun Jun 11 21:08:59 2017 DESKTOP-DHNB9O5
##

NAME			=	../server

SRCS			=	srcs/main.c			\
				srcs/core.c			\
				srcs/list.c         \
				srcs/tab.c			\
				srcs/args/ask_help.c		\
				srcs/args/check.c		\
				srcs/client/create.c		\
				srcs/client/delete.c		\
				srcs/client/list/add.c		\
				srcs/error/display.c		\
				srcs/socket/accept.c		\
				srcs/socket/bind.c		\
				srcs/socket/connect.c		\
				srcs/socket/create.c		\
				srcs/socket/listen.c		\
				srcs/socket/select.c		\
				srcs/transfer/receive.c		\
				srcs/transfer/send.c		\
				srcs/cmd/server/check_connected.c   \
				srcs/cmd/server/user.c              \
				srcs/cmd/server/nick.c              \
				srcs/cmd/server/users.c             \
				srcs/cmd/server/quit.c              \
				srcs/cmd/dispatcher.c               \
				srcs/cmd/channel/join.c             \
				srcs/cmd/channel/list.c             \
				srcs/cmd/channel/names.c            \
				srcs/cmd/channel/channel.c          \
				srcs/cmd/channel/part.c             \
				srcs/cmd/message/send_msg_to.c      \
				srcs/cmd/message/send_msg_all.c \
				srcs/cmd/message/send_message.c     \
				srcs/cmd/file_transfer/accept_file.c    \
				../circular-buffer/buff_read.c	\
				../circular-buffer/buff_write.c	\
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
