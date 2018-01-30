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
    if (nb > 9)
            put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
}

void my_put_base(unsigned long long int nbr, char *base)
{
  int i;
  unsigned int size;

  i = 12;
  size = my_strlen(base);
  if (nbr > size - 1)
    {
      i = nbr % size;
      my_put_base(nbr / size, base);
      my_putchar(base[i]);
    }
  else
    my_putchar(base[nbr]);
}

void putstr(char *str)
{
	write(1, str, my_strlen(str));
}

void show_alloc_mem()
{
        putstr("break : ");
        my_put_base(sbrk(0), "0123456789ABCDEF");
        putstr("\n");
}