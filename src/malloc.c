/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** zaze
*/

#include "malloc.h"
#include <pthread.h>

t_info *head = NULL;
pthread_mutex_t mutex;

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
	pthread_mutex_lock(&mutex);
	size = (size + (sizeof(size_t) - 1)) & ~(sizeof(size_t) - 1);
	block = (char *) new_block(size, head);
	pthread_mutex_unlock(&mutex);
	return (block);
}
