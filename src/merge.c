/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** merge
*/

#include "malloc.h"

void merge_next(t_header *header, t_info *head)
{
	if (header->is_free == 1 && header->next && header->next->is_free) {
		header->size += HEADER_SIZE + header->next->size;
		header->next = header->next->next;
		if (header->next)
			header->next->prev = header;
		head->nbr_ptr--;
		head->nbr_free_ptr--;
	}
}


void merge_prev(t_header *header, t_info *head)
{
	if (header->is_free == 1 && header->prev && header->prev->is_free) {
		merge_next(header->prev, head);
	}
}
