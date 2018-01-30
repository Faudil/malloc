/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** calloc
*/

#include "malloc.h"

void *calloc(size_t nmemb, size_t size)
{
        char *new;

        if (nmemb == 0 || size == 0)
                return (NULL);
        new = malloc(nmemb * size);
        if (new == NULL)
                return (NULL);
	for (size_t i = 0; i < nmemb * size; i++) {
		new[i] = 0;
	}
        return ((void *) new);
}
