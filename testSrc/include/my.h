/*
** my.h for libmy in /home/guacamole/Epitech/lib
** 
** Made by guacamole
** Login   <faudil.puttilli@epitech.eu>
** 
** Started on  Tue Apr 18 16:02:50 2017 guacamole
** Last update Tue Aug  1 19:53:58 2017 guacamole
*/

#ifndef BOOL
# define BOOL

# define TRUE 1
# define FALSE 0
typedef char bool;
#endif /* BOOL */

#ifndef BYTE
# define BYTE

typedef unsigned char byte;

#endif /* BYTE */

#ifndef STATUS
# define STATUS

# define SUCCESS 0
# define FAILURE 84

#endif /* STATUS */

#ifndef MY_H_
# define MY_H_

# define READ_SIZE 4096

int	my_printf(char *, ...);

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_put_nbr(int nb);
int	put_err(char *str);

/*
** Nbr function
**
*/

int	my_getnbr(char *str);
int	my_isneg(int n);
int	my_swap(int *a, int *b);
int	my_power_rec(int nb, int p);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_next_prime(int nb);

/*
** Str function
**
*/

char	*my_strcpy(char *dest, char *src);
char	*my_strcat(char *dest, char *src);
char	*my_strmemcat(char *dest, char *src);
char	*my_strmemcatf(char *dest, char *src);
char	*my_strmemcat2f(char *dest, char *src);

char	*my_strmemcat_sep(char *dest, char *src, char sep);
char	*my_strmemcatf_sepf(char *dest, char *src, char sep);
char	*my_strmemcat2f_sep2f(char *dest, char *src, char sep);

char	*my_revstr(char *str);
int	my_strlen(char *str);
int	my_str_isprintable(char *str);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
char	*start_str_from_ch(char *str, char c);

/*
** Char info
**
*/

int	my_str_isalpha(char *str);
int	my_str_inum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_begin_with(const char *str, const char *begin);

char	*my_strncat(char *dest, char *src, int n);
char	*my_strdup(char *str);
int	my_str_isnum(char *str);
int	my_str_isnumalpha(char *str);
int	index_of_ch(char *str, char to_search);
void	str_replace_ch(char *str, char to_replace, char replacer);
char	*epur_str(char *str);
char	*epur_strf(char *str);

/*
** Memory handling function
**
*/

void	my_showmem(void *mem_ptr, int size);

/*
** Tab function
**
*/

char	**str_to_wordtab(char *str, char sep);
int	tab_len(char **tab);
void	free_tab(char **tab);
void	my_sort_int_tab(int *tab, int size, int (*cmp) (int, int));

/*
** Match and Nmatch
**
*/

int	match(char *s1, char *s2);
int	nmatch(char *s1, char *s2);

/*
**Read file and get_next_line
**
*/

char	*read_file(char *file);
char	*read_file_cat(char *file);
char	*get_next_line(int fd);

/*
**List function and structure
**
*/

typedef struct		s_list
{
  void			*data;
  struct	s_list	*next;
  struct	s_list	*prev;
  struct	s_list	*(*index)(struct s_list *, int);
  struct	s_list	*(*add)(struct s_list *, void *);
}			t_list;

t_list	*get_elem(t_list *list, int index);
t_list	*add_elem(t_list *list, void *content);
t_list	*create_elem(void *content);
t_list	*init_list(void *content);
char	**list_to_strtab(t_list *list);
t_list	*strtab_to_list(char **tab);
int	len_list(t_list *);
void	destroy_elem(t_list *list);
void	bubble_sort(t_list **list, int (*cmp) (t_list *, t_list *));
void	free_list(t_list *list);

#endif /* !MY_H_ */
