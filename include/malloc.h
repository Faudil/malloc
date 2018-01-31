/*
** malloc.h for malloc in /home/guacamole/Epitech/malloc/testSrc
** 
** Made by guacamole
** Login   <faudil.puttilli@epitech.eu>
** 
** Started on  Thu Sep  7 20:10:31 2017 guacamole
** Last update Wed Jan 31 13:26:07 2018 guacamole
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# define HEADER_SIZE  sizeof(t_header)

# define GET_HEADER(block) ((t_header *)(block) - 1)
# define GET_BLOCK(header) ((t_header *)(header) + 1)

#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

typedef struct		s_header
{
	size_t		size;
	size_t		id;
	char		is_free;
	struct s_header	*next;
} __attribute__((packed)) t_header;

typedef	struct		s_info
{
	t_header		*begin;
	t_header		*end;
	size_t			page_allocated;
	size_t			to_fill;
	size_t			nbr_ptr;
	size_t			nbr_free_ptr;
} __attribute__((packed)) t_info;

void *malloc(size_t);
void *calloc(size_t, size_t);
void *realloc(void *, size_t);

void free(void *);
void split_block(size_t, t_info *, t_header *);
void *new_block(size_t, t_info *);
void update_head(t_header *, t_info *);
t_header *find_free_memory(size_t , t_info *);
t_header *create_new_block(size_t , t_info *);

void *alloc_page(size_t, t_info *);

t_header *getPrev(t_header *);

#endif /* !MALLOC_H_ */
