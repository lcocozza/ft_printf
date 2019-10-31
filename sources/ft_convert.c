#include "ft_printf.h"

char	*ft_uitoa_base(unsigned int nb, int base)
{
	char *result;
	int i;
	
	i = 0;
	result = ft_strnew(11);
	while (nb)
	{	
		result[i++] = (nb % base) + ((base == 16 && (nb % base) > 9) ? 55 : '0');
		nb /= base;
	}
	return ft_strrev(result);
}
