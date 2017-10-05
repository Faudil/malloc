##
## Makefile for malloc in /home/guacamole/Epitech/malloc
## 
## Made by guacamole
## Login   <faudil.puttilli@epitech.eu>
## 
## Started on  Tue Sep 26 20:16:17 2017 guacamole
## Last update Tue Sep 26 20:16:18 2017 guacamole
##

CC	=	gcc -g

RM	=	rm -f

FLAGS	+=	-Iinclude -Wall -Wextra

CPPFLAGS	+=	-I include/ -Wall -Wextra -W

NAME	=	libmalloc.a

SRC	=	src/init_memory.c	\
		src/malloc.c		\
		src/free.c		\
		src/list.c		\
		src/split_block.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ) 
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	$(NAME)

.PHONY:	all clean fclean re
