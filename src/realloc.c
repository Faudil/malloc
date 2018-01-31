/*
** realloc.c for malloc in /home/guacamole/Epitech/malloc
** 
** Made by guacamole
** Login   <faudil.puttilli@epitech.eu>
** 
** Started on  Tue Sep 19 19:53:58 2017 guacamole
** Last update Tue Jan 30 16:44:33 2018 guacamole
*/

#include "malloc.h"

extern t_info *head;

size_t get_buffer_size(void *buffer)
{
	t_header *header = GET_HEADER(buffer);
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
	for (size_t i = 0, old = get_buffer_size(ptr); i < old && i < size;i++)
                new[i] = chptr[i];
        free(ptr);
        return ((void *) new);
}
