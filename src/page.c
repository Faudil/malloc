/*
** EPITECH PROJECT, 2018
** azde
** File description:
** azfzegr
*/

#include "malloc.h"

void *alloc_page(size_t nb_page, t_info *head)
{
	void *block = sbrk(getpagesize() * nb_page);

	if (block == (void *) -1)
		return (NULL);
	head->to_fill += getpagesize() * nb_page;
	head->page_allocated++;
	return (block);
}
