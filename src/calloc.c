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
	size_t all = nmemb * size;

	if (nmemb == 0 || size == 0)
		return (NULL);
	new = malloc(all);
	if (new == NULL)
		return (NULL);
	for (size_t i = 0; i < all; i++)
		new[i] = 0;
	return ((void *) new);
}
