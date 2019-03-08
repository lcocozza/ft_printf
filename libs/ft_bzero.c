#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	int i;
	char *tmp;

	i = 0;
	tmp = (char *)s;
	while (n--)
		tmp[i++] = '\0';
}
