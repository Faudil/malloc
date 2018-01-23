##
## Makefile for malloc in /home/guacamole/Epitech/malloc
## 
## Made by guacamole
## Login   <faudil.puttilli@epitech.eu>
## 
## Started on  Tue Sep 26 20:16:17 2017 guacamole
## Last update Tue Jan 23 15:40:56 2018 guacamole
##

CC = gcc

RM = rm -f

FLAGS += -Wall -Wextra

CPPFLAGS += -I include/ -Wall -Wextra

NAME = libmy_malloc.so

SRCS 	= 	src/init_memory.c	\
		src/malloc.c		\
		src/calloc.c		\
		src/realloc.c		\
		src/free.c		\
		src/list.c		\
		src/page.c		\
		src/split_block.c

OBJDIR = objs/

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o : %.c
	mkdir -p $(OBJDIR)
	mkdir -p $(@D)
	$(CC) -c -fPIC $< -o $@ $(CPPFLAGS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -shared -o $(NAME) $(FLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

