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
	while (header && header != head->end)
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

t_header *create_new_block(size_t size, t_info *head)
{
	t_header *header;
	static size_t id = 0;
	t_header *old_last = head->end;
	char *block = NULL;

	if (old_last == NULL) {
		block = (char *) (head);
		block += sizeof(t_info);
	}
	else {
		block = (char *) old_last;
		block += old_last->size + (size_t) sizeof(t_header);
		old_last->next = (t_header *) block;
	}
	if ((char *) (block + sizeof(t_header) + size) >= (char *) sbrk(0))
		alloc_page(size / getpagesize() + 1, head);
	if (block == NULL)
		return NULL;
        head->to_fill -= size + sizeof(t_header) + 1;
	header = (t_header *) block;
 	header->size = size;
	header->id = id++;
	header->is_free = 0;
	header->next = NULL;
	update_head(header, head);
	return ((t_header *) block);
}

void *new_block(size_t size, t_info *head)
{
	t_header *block = NULL;

	if (head->nbr_free_ptr > 0)
		block = find_free_memory(size, head);
	if (block)
		return (GET_BLOCK(block));
	block = create_new_block(size, head);
	if (block)
		return (GET_BLOCK(block));
	return (NULL);
}
