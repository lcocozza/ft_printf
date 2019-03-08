#include "ft_printf.h"

int	ft_printf(const char *format, ... )
{
	t_format info_f;
	int i;
	
	i = 0;
	info_f = ft_split_format(format);
	if (info_f.nb_ap < 2)
	{
		ft_putstr(format);
		return ft_strlen(format);
	}
	va_start(info_f.ap, format);
	while (i < info_f.nb_ap)
	{
		ft_putstr(info_f.str[i]);
		ft_putchar('\n');
		i++;
	}
	va_end(info_f.ap);
	return 0;
}
