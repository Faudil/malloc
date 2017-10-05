/*
** realloc.c for malloc in /home/guacamole/Epitech/malloc
** 
** Made by guacamole
** Login   <faudil.puttilli@epitech.eu>
** 
** Started on  Tue Sep 19 19:53:58 2017 guacamole
** Last update Tue Sep 19 20:02:53 2017 guacamole
*/

#include "malloc.h"

extern t_info *head;

void		*realloc(void *ptr, size_t size)
{
  int		i;
  void		*new;
  t_header	*header;

  i = 0;
  new = malloc(size);
  if (new == NULL || ptr == NULL)
    return (new);
  while ()
    {

    }
  return (new);
}
