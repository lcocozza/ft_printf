#include "ft_printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char *tmp;
	int i;

	i = 0;
	tmp = (char *)s;
	while (n--)
		tmp[i++] = c;
	return s;
}
