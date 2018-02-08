/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** header
*/

#include "malloc.h"

void split_block(size_t size, t_info *head, t_header *header)
{
	uintptr_t new = ((uintptr_t) header) + HEADER_SIZE + size;
	t_header *new_header = (t_header *) new;

	if (header->size > HEADER_SIZE + size) {
		new_header->is_free = 2;
		if (head->end == header)
			head->end = new_header;
		new_header->next = header->next;
		new_header->prev = header;
		new_header->size = header->size - size - HEADER_SIZE;
		header->next = new_header;
		if (header->next)
			header->next->prev = new_header;
		header->size = size;
		head->nbr_ptr++;
		head->nbr_free_ptr++;
	}
}
