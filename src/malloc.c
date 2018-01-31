/*
** malloc.c for malloc in /home/guacamole/Epitech/malloc
** 
** Made by guacamole
** Login   <faudil.puttilli@epitech.eu>
** 
** Started on  Tue Aug 29 19:57:10 2017 guacamole
** Last update Wed Jan 31 13:21:07 2018 guacamole
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
	void *block;

	if (head == NULL)
		head = init_head();
	if (head == NULL)
		return (NULL);
	block = new_block(size, head);
	return (block);
}
