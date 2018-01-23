/*
** EPITECH PROJECT, 2018
** azde
** File description:
** azfzegr
*/

#include "malloc.h"

void *alloc_page(int nbPage, t_info *head)
{
	void *block = sbrk(getpagesize());

	if (block == (void *) -1)
		return (NULL);
	head->to_fill += getpagesize();
	for (int i; i < nbPage; i++) {
		if (sbrk(getpagesize()) == (void *) -1)
			return (NULL);
	}
	return (block);
}
