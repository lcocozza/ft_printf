#include "ft_printf.h"

int	ft_strfind_c(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return 1;
		i++;
	}
	return 0;
}
