##
## EPITECH PROJECT, 2018
## malloc
## File description:
## malloc
##

CC = gcc -O2

RM = rm -f

FLAGS += -Wall -Wextra

CPPFLAGS += -I include/ -Wall -Wextra

NAME = libmy_malloc.so

SRCS 	= 	src/init_memory.c	\
		src/malloc.c		\
		src/calloc.c		\
		src/realloc.c		\
		src/free.c		\
		src/page.c		\
		src/merge.c		\
		src/show_alloc_mem.c	\
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

