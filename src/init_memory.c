/*
** EPITECH PROJECT, 2018
** azfazhf
** File description:
** azfaz
*/

#include "malloc.h"
#include <string.h>

void update_head(t_header *header, t_info *head)
{
	if (head->begin == NULL)
		head->begin = header;
	head->end = header;
	head->nbr_ptr++;
}

t_header *find_free_memory(size_t size, t_info *head)
{
	t_header *header;
	t_header *least;

	header = head->begin;
	least = NULL;
	while (header)
	{
		if (header->is_free == 1 && header->size == size) {
			header->is_free = 0;
			return (header);
		}
		else if (header->is_free == 1 && header->size > size)
			least = header;
		header = header->next;
	}
	if (least) {
		split_block(size, head, least);
		least->is_free = 0;
	}
	return (least);
}

static void init_header(t_header *to_init, const size_t size)
{
	to_init->size = size;
	to_init->is_free = 0;
	to_init->next = NULL;
}

t_header *create_new_block(size_t size, t_info *head)
{
	uintptr_t old_last = (uintptr_t) head->end;
	t_header *header_last = head->end;
	uintptr_t block_pos = 0;

	if (size + HEADER_SIZE >= head->to_fill) {
		if (!alloc_page((size + HEADER_SIZE) / getpagesize() + 1, head))
			return (NULL);
	}
	if (old_last == 0)
		block_pos = (uintptr_t) (head + 1);
	else
		block_pos = old_last + HEADER_SIZE + header_last->size;
	init_header((t_header *) block_pos, size);
	if (header_last)
		header_last->next = (t_header *) block_pos;
	update_head((t_header *) block_pos, head);
	head->to_fill -= HEADER_SIZE + size;
	return ((t_header *) block_pos);
}

void *new_block(size_t size, t_info *head)
{
	t_header *block = NULL;

	if (head->nbr_free_ptr > 0)
		block = find_free_memory(size, head);
	if (block) {
		head->nbr_free_ptr--;
		return (block->data);
	}
	block = create_new_block(size, head);
	if (block)
		return (block->data);
	return (NULL);
}
