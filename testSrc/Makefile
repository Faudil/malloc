##
## Makefile for BSQ in /home/guacamole/Epitech/delivery/CPE_2016_BSQ	
## 
## Made by Faudil Puttilli
## Login   <faudil.puttilli@epitech.eu@epitech.net>
## 
## Started on  Mon Dec 12 13:56:55 2016 Faudil Puttilli
## Last update Tue Sep 12 20:16:50 2017 guacamole
##

CC	= 	gcc -g

RM	= 	rm -f

CFLAGS	+=	-I./include -W -Wall

LDFLAGS += -L lib -lmy -lmalloc

NAME    = 	test_malloc

SRCS    = 	src/main.c			\

OBJS	=	$(SRCS:%.c=obj/%.o)

all: $(NAME)

obj/%.o: %.c
	@mkdir -p obj/src
	$(CC) -c -o $@ $< $(LDFLAGS) $(CFLAGS)

$(NAME): $(OBJS)
	$(CC)  $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) -rf obj

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
