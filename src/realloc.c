/*
** realloc.c for malloc in /home/guacamole/Epitech/malloc
** 
** Made by guacamole
** Login   <faudil.puttilli@epitech.eu>
** 
** Started on  Tue Sep 19 19:53:58 2017 guacamole
** Last update Wed Nov 15 19:20:59 2017 guacamole
*/

#include "malloc.h"

extern t_info *head;

void		*realloc(void *ptr, size_t size)
{
  size_t	i;
  char		*new;
  char		*chptr;

  write(1, "R\n", 2);
  i = 0;
  chptr = (char *) ptr;
  new = malloc(size);
  if (new == NULL || ptr == NULL)
    return (new);
  while (i < size)
    {
      new[i] = chptr[i];
      ++i;
    }
  return ((void *) new);
}
