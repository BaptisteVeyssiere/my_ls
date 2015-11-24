##
## Makefile for ls in /home/VEYSSI_B/rendu/PSU_2015_my_ls
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Mon Nov 23 10:38:43 2015 Baptiste veyssiere
## Last update Tue Nov 24 17:52:30 2015 Baptiste veyssiere
##

NAME	= my_ls

SRCS	= my_ls.c \
	my_strcpy.c \
	my_strlen.c \
	my_put.c \
	flags.c \
	sort.c

OBJS	= $(SRCS:.c=.o)

$(NAME):
	cc -c $(SRCS) -I./include
	cc -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all