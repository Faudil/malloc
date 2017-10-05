/*
** split_block.c for malloc in /home/guacamole/Epitech/malloc
** 
** Made by guacamole
** Login   <faudil.puttilli@epitech.eu>
** 
** Started on  Wed Sep  6 20:20:25 2017 guacamole
** Last update Thu Sep  7 20:25:13 2017 guacamole
*/

#include "malloc.h"

void	split_block(size_t size, t_info *head, t_header *header)
{
  t_header	*new;

  if (header->size > size + sizeof(t_header))
    {
      new = (t_header *) header + size;
      new->is_free = 1;
      new->next = header->next;
      new->size = header->size - size - sizeof(t_header);
      header->next = new;
      head->nbr_free_ptr++;
    }
}
