#include "ft_printf.h"

int	ft_printf(const char *format, ... )
{
	va_list ap;
	t_format info_f;
	int i;
	
	i = 0;
	va_start(ap, format);
	info_f = ft_split_format(format);
	if (info_f.nb_ap < 2)
	{
		ft_putstr(format);
		va_end(ap);
		return ft_strlen(format);
	}
	while (i < info_f.nb_ap)
	{
		ft_putstr(info_f.str[i]);
		ft_putchar('\n');
		i++;
	}
	va_end(ap);
	return 0;
}
