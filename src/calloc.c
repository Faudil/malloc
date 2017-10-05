/*
** calloc.c for malloc in /home/guacamole/Epitech/malloc
** 
** Made by guacamole
** Login   <faudil.puttilli@epitech.eu>
** 
** Started on  Mon Sep 18 20:30:49 2017 guacamole
** Last update Mon Sep 18 20:35:48 2017 guacamole
*/

#include "malloc.h"

void	*calloc(size_t nmemb, size_t size)
{
  void	*new;
  int	i;

  if (nmemb == 0 || size == 0)
    return (NULL);
  new = malloc(nmemb * size);
  if (new == NULL)
    return (NULL);
  i = 0;
  while (i < size)
    {
      new[i] = 0;
      i++;
    }
  return (new);
}
