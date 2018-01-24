/*
** free.c for malloc in /home/guacamole/Epitech/malloc
** 
** Made by guacamole
** Login   <faudil.puttilli@epitech.eu>
** 
** Started on  Thu Sep  7 20:04:49 2017 guacamole
** Last update Wed Jan 24 13:34:28 2018 guacamole
*/

#include "malloc.h"

extern t_info *head;

void free_last()
{
	t_header *header;

	if (head->end != head->begin)
	{
		header = head->end;
		header = getPrev(head->end);
		header->next = NULL;
		head->end = header;
	}
	head->to_fill += header->size + sizeof(t_header);
	head->nbr_ptr--;
}

void markAsFree(t_header *header)
{
	header->is_free = 0;
	head->nbr_free_ptr++;
}

void free(void *block)
{
	t_header *header;

	if (head == NULL)
		return ;
	header = GET_HEADER(block);
	if (header == head->end)
		free_last();
	else {
		header->is_free = 0;
	}
	if (head->nbr_ptr == head->nbr_free_ptr)
	{
		brk(head);
		head = NULL;
	}
}
