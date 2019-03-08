#include "ft_printf.h"

char	*ft_itoa(int n)
{
	int i;
	int b;
	int reste;
	char *tmp;

	i = 0;
	b = 0;
	tmp = ft_strnew(13);
	if (tmp == NULL || n == 0)
		return ((n == 0) ? "0" : NULL);
	if (n < 0)
	{
		b = 1;
		n *= -1;
	}
	while (n)
	{
		reste = n % 10;
		tmp[i++] = reste + '0';
		n /= 10;
	}
	if (b)
		tmp[i] = '-';
	return ft_strrev(tmp);
}
