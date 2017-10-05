##
## Makefile for malloc in /home/guacamole/Epitech/malloc
## 
## Made by guacamole
## Login   <faudil.puttilli@epitech.eu>
## 
## Started on  Tue Sep 26 20:16:17 2017 guacamole
## Last update Thu Oct  5 19:45:59 2017 guacamole
##

CC = gcc

RM = rm -f

FLAGS += -Wall -Wextra

CPPFLAGS += -I include/ -Wall -Wextra

NAME = libmy_malloc.so

SRCS 	= 	src/init_memory.c	\
		src/malloc.c		\
		src/free.c		\
		src/list.c		\
		src/split_block.c

OBJDIR = objs/

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o : %.c
	mkdir -p $(OBJDIR)
	mkdir -p $(@D)
	$(CC) -g -c -fPIC $< -o $@ $(CPPFLAGS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -g -shared -o $(NAME) $(FLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

