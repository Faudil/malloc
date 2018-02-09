/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** free
*/

#include "malloc.h"

extern t_info *head;

void mark_as_free(t_header *header)
{
	header->is_free = 1;
	head->nbr_free_ptr++;
}

void free(void *block)
{
	t_header *header;
	uintptr_t h_pos = (uintptr_t) block;

	if (!head || !block || (t_info *) block < head)
		return;
        h_pos -= sizeof(t_header);
        header = (t_header *) h_pos;
	mark_as_free(header);
	merge_next(header, head);
	merge_prev(header, head);
        if (head->nbr_ptr == head->nbr_free_ptr) {
		brk(head);
		head = NULL;
	}
}
