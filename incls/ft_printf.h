#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define PARAMS "%sSpdDioOuUxXcC"
#define NBPARAM ft_strlen(PARAMS)
#define LENPARAM 3

typedef struct s_format
{
	char **str;
	int nb_ap;
}	t_format;

/*
*	srcs/
*/
int	ft_printf(const char *format, ... );
t_format	ft_split_format(char const *format);
int	ft_detect_format(t_format info_f, int i);

/*
*	libs/
*/
void	ft_putstr(char const *s);
void	ft_putnbr(int nb);
void	ft_putchar(int c);
size_t	ft_strlen(const char *s);
int	ft_strfind(const char *s, const char *chr);
char	*ft_strcpy(char *dest, char const *src);

#endif
