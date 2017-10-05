/*
** main.c for  in /home/guacamole/Epitech/malloc
** 
** Made by guacamole
** Login   <faudil.puttilli@epitech.eu>
** 
** Started on  Thu Sep  7 20:05:59 2017 guacamole
** Last update Tue Sep 26 20:26:55 2017 guacamole
*/

#include "my.h"
#include "malloc.h"

int testStr(char *str)
{
  int i = 0;
  while (str[i])
    i++;
  write(1, str, i);
  return (0);
}
int	testA() // Just One malloc
{
  void *a = malloc(10);
  my_printf("testA succeed\n");
  return (0);
}

int	testB() // Malloc and free
{
  void *a = malloc(12);
  free(a);
  //  my_printf("testB succeed\n");
  return (0);
}

int	testC() //
{
  void	*a = malloc(3);
  void	*b = malloc(6);
  free(b);
  free(a);
  //  my_printf("testC succeed\n");
  return (0);
}

int	testD() // inverted free testC
{
  void	*a = malloc(3);
  void	*b = malloc(6);
  free(a);
  free(b);
  //  my_printf("testC succeed\n");
  return (0);
}

int	testSplit()
{
  void	*a = malloc(3);
  void	*b = malloc(6);
  void	*c = malloc(6);
  free(b);
  b = malloc(3);
  free(a);
  free(c);
  free(b);
  return (0);
}

int	main()
{
  //  testA();
  testB();
  testC();
  testD();
  testSplit();
  return (0);
}
