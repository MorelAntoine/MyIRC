##
## Makefile for irc in /home/dylan/Documents/TEK2/PSU_2016_myirc
## 
## Made by Dylan Deu
## Login   <dylan.deu@epitech.eu>
## 
## Started on  Wed Jun  7 20:30:56 2017 Dylan Deu
## Last update Wed Jun  7 20:30:59 2017 Dylan Deu
##

all			:	client server

client			:
				make -C client-project/

server			:
				make -C server-project/

clean			:
				make -C client-project/ clean
				make -C server-project/ clean

fclean			:	clean
				make -C client-project/ fclean
				make -C server-project/ fclean

re			:	fclean all

.PHONY			:	all clean fclean re
