/*
** list.c for malloc in /home/guacamole/Epitech/malloc
** 
** Made by guacamole
** Login   <faudil.puttilli@epitech.eu>
** 
** Started on  Thu Sep 14 20:29:23 2017 guacamole
** Last update Tue Jan 30 17:27:19 2018 guacamole
*/

#include "malloc.h"

extern t_info *head;

t_header *getPrev(t_header *ptr)
{
	t_header *it;

	it = head->begin;
	while (it->next && it->next != ptr) {
		it = it->next;
	}
	return (it);
}
