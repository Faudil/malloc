/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** free
*/

#include "malloc.h"

extern t_info *head;

void free_last()
{
	t_header *header;
	t_header *last = head->end;

	if (head->end != head->begin)
	{
		header = head->end->prev;
		header->next = NULL;
		head->end = header;
	}
	head->to_fill += HEADER_SIZE + last->size;
	head->nbr_ptr--;
}

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
        if (head->nbr_ptr == head->nbr_free_ptr) {
		brk(head);
		head = NULL;
	}
}
