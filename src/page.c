/*
** EPITECH PROJECT, 2018
** azde
** File description:
** azfzegr
*/

#include "malloc.h"

void *alloc_page(int nb_page, t_info *head)
{
	void *block = sbrk(getpagesize() * nb_page);

	if (block == (void *) -1)
		return (NULL);
	head->to_fill += getpagesize() * nb_page;
	return (block);
}
