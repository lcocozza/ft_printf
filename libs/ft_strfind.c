#include "ft_printf.h"

int	ft_strfind(const char *str, const char *chr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] && chr[j])
	{
		if (str[i++] == chr[j])
			j++;
		else
			j = 0;
	}
	return ((j) ? 1 : 0);
}
