/*
** split_block.c for malloc in /home/guacamole/Epitech/malloc
** 
** Made by guacamole
** Login   <faudil.puttilli@epitech.eu>
** 
** Started on  Wed Sep  6 20:20:25 2017 guacamole
** Last update Tue Jan 30 17:27:32 2018 guacamole
*/

#include "malloc.h"

void split_block(size_t size, t_info *head, t_header *header)
{
	char *new;
	static int id = 0;
	t_header *new_header;

	if (header->size > size + sizeof(t_header))
	{
		new = (char *) header;
		new += sizeof(t_header) + size;
		new_header = (t_header *) new;
		new_header->is_free = 1;
		new_header->id = 50000 + id++;
		if (head->end == header)
			head->end = new_header;
		new_header->next = header->next;
		new_header->size = header->size - size - sizeof(t_header);
		header->next = new_header;
		header->size -= sizeof(t_header) + new_header->size;
		head->nbr_free_ptr++;
		head->nbr_ptr++;
	}
}
