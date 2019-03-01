#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_printf(const char *format, ... );

/*
*	libft
*/
void	ft_putstr(char const *s);
void	ft_putnbr(int nb);
void	ft_putchar(int c);
size_t	ft_strlen(const char *s);

#endif
