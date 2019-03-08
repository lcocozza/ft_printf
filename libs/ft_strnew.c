#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char *tmp;

	tmp = NULL;
	tmp = malloc(sizeof(char) * size);
	if (tmp == NULL)
		return NULL;
	ft_bzero(tmp, size);
	return tmp;
}
