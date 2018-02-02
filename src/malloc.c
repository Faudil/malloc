/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** zaze
*/

#include "malloc.h"

t_info *head = NULL;

t_info *init_head()
{
	t_info	*info;

	info = sbrk(getpagesize());
	if (info == (void *) -1)
		return (NULL);
	info->begin = NULL;
	info->end = NULL;
	info->nbr_ptr = 0;
	info->nbr_free_ptr = 0;
	info->page_allocated = 1;
	info->to_fill = getpagesize() - sizeof(t_info);
	return (info);
}

void *malloc(size_t size)
{
	char *block;

	if (head == NULL)
		head = init_head();
	if (head == NULL)
		return (NULL);
	size = (((((size) - 1) >> 2) << 2) + 4);
	block = (char *) new_block(size, head);
	for (size_t i = 0; i < size; i++)
		block[i] = 0;
	return (block);
}
