/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** realloc
*/

#include "malloc.h"

extern t_info *head;

size_t get_buffer_size(void *buffer)
{
	t_header *header = (t_header *) buffer - 1;
	return (header->size);
}

void *realloc(void *ptr, size_t size)
{
	char *new;
	char *chptr;

	if (ptr && size == 0) {
		free(ptr);
		return (NULL);
	}
	chptr = (char *) ptr;
	new = malloc(size);
	if (new == NULL || ptr == NULL)
		return (new);
	for (size_t i = 0, old = get_buffer_size(ptr);
	     i < old && i < size; i++)
		new[i] = chptr[i];
	free(ptr);
	return ((void *) new);
}
