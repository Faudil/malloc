/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** header
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# define HEADER_SIZE  sizeof(t_header)

# define GET_HEADER(block) (((t_header *) block) - 1)
# define GET_BLOCK(header) (((t_header *) header) + 1)

#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

typedef struct		s_header
{
	size_t		magic;
	size_t		size;
	char		is_free;
	struct s_header	*next;
	struct s_header	*prev;
	char		data[1];
} t_header;

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

void merge_prev(t_header *, t_info *);
void merge_next(t_header *, t_info *);

#endif /* !MALLOC_H_ */
