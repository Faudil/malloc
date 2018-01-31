/*
** EPITECH PROJECT, 2018
** azfz
** File description:
** malloc
*/

#include "malloc.h"

extern t_info *head;

t_header *getPrev(t_header *ptr)
{
	t_header *it = head->begin;

	while (it->next && it->next != ptr) {
		it = it->next;
	}
	return (it);
}
