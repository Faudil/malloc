/*
** init_memory.c for my_malloc in /home/guacamole/Epitech/malloc
** 
** Made by guacamole
** Login   <faudil.puttilli@epitech.eu>
** 
** Started on  Tue Aug 29 20:22:27 2017 guacamole
** Last update Mon Jan 22 14:52:18 2018 guacamole
*/

#include "malloc.h"
#include <unistd.h>

void update_head(t_header *header, t_info *head)
{
	if (head->begin == NULL)
		head->begin = header;
	head->end = header;
	head->nbr_ptr++;
}

void *find_free_memory(size_t size, t_info *head)
{
	t_header *header;
	t_header *least;

	header = head->begin;
	least = NULL;
	while (header != head->end)
	{
		if (header->is_free == 1 && header->size == size)
			return ((void *) (header));
		else if (header->is_free == 1 && header->size >= size)
			least = header;
		header = header->next;
	}
	if (least)
		split_block(size, head, least);
	return (least);
}

void *create_new_block(size_t size, t_info *head)
{
	t_header *header;
	t_header *old_last;
	void *block;

	if (size > to_fill)
		block = sbrk(size + sizeof(t_header));
	if (block == (void *) -1)
		return NULL;
	old_last = head->end;
	if (old_last != NULL)
		old_last->next = block;
	header = (t_header *) block;
	header->size = size;
	header->is_free = 0;
	header->next = NULL;
	update_head(header, head);
	return (block);
}

void *new_block(size_t size, t_info *head)
{
	void *block;

	block = NULL;
	if (head->nbr_free_ptr > 0)
		block = find_free_memory(size, head);
	if (block)
		return (GET_BLOCK(block));
	return (GET_BLOCK(create_new_block(size, head)));
}
