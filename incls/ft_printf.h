#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define PARAMS "%sSpdDioOuUxXcC"
#define NBPARAM ft_strlen(PARAMS)
#define LENPARAM 3

//%o = ft_uitoa_base(nb, base); (base 8)
//%u = ft_uitoa_base(nb, base); (base 10)
//%X = ft_uitoa_base(nb, base); (base 16)
//%x = ft_lowercase(ft_uitoa_base(nb, base)); (base 16)
//%d,i = ft_itoa(nb);
//%sS = ft_putstr(str);
//%cC = ft_putchar(c);
//%% = ft_putchar('%');

typedef struct s_format
{
	char **str;
	int nb_ap;
	va_list ap;
}	t_format;

/*
*	srcs/
*/
int	ft_printf(const char *format, ... );
t_format	ft_split_format(char const *format);
int	ft_detect_format(t_format info_f, int i);
char	*ft_uitoa_base(unsigned int nb, int base);

/*
*	libs/
*/
void	ft_putstr(char const *s);
void	ft_putnbr(int nb);
void	ft_putchar(int c);
size_t	ft_strlen(const char *s);
int	ft_strfind(const char *s, const char *chr);
char	*ft_strcpy(char *dest, char const *src);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_strnew(size_t size);
char	*ft_strrev(char *str);
char	*ft_itoa(int n);
int	ft_strfind_c(const char *s, int c);
char	*ft_strlowcase(char *str);

#endif
