/*
** EPITECH PROJECT, 2018
** azfr
** File description:
** zeger
*/

#include "malloc.h"

extern t_info *head;

int my_strlen(char *s)
{
        int i;

        for (i = 0; s[i]; i++);
        return (i);
}

void put_nbr(long long nb)
{
	char c;

	if (nb > 9)
		put_nbr(nb / 10);
	c = nb % 10 + '0';
        write(1, &c, 1);
}

void my_put_base(uintptr_t  nbr, char *base)
{
	int i;
	unsigned int size;

	i = 12;
	size = my_strlen(base);
	if (nbr > size - 1)
	{
		i = nbr % size;
		my_put_base(nbr / size, base);
		write(1, &base[i], 1);
	}
	else
		write(1, &base[nbr], 1);
}

void putstr(char *str)
{
	write(1, str, my_strlen(str));
}

void show_alloc_mem()
{
	t_header *header = head->begin;

        putstr("break : ");
	my_put_base((uintptr_t) sbrk(0), "0123456789ABCDEF");
	write(1, "\n", 1);
	while (header) {
		my_put_base((uintptr_t) GET_BLOCK(header), "0123456789ABCDEF");
		write(1, " - ", 3);
		my_put_base(((uintptr_t) GET_BLOCK(header)) + header->size,
			    "0123456789ABCDEF");
		write(1, "\n", 1);
		header = header->next;
	}
}
