/*
** split_block.c for malloc in /home/guacamole/Epitech/malloc
** 
** Made by guacamole
** Login   <faudil.puttilli@epitech.eu>
** 
** Started on  Wed Sep  6 20:20:25 2017 guacamole
** Last update Wed Jan 31 13:27:49 2018 guacamole
*/

#include "malloc.h"

void split_block(size_t size, t_info *head, t_header *header)
{
	uintptr_t new = ((uintptr_t) header) + HEADER_SIZE + size;
	t_header *new_header = (t_header *) new;

	if (header->size > HEADER_SIZE + size) {
		new_header->is_free = 1;
		if (head->end == header)
			head->end = new_header;
		new_header->next = header->next;
		new_header->size = header->size - size - HEADER_SIZE;
		header->next = new_header;
		header->size -= HEADER_SIZE + new_header->size;
		head->nbr_ptr++;
		head->nbr_free_ptr++;
	}
}
