#include "ft_printf.h"

static int	ft_seglen(char const *s, int i)
{
	int len;

	len = 0;
	if (s[i] == '%')
	{
		len++;
		i++;
		if (s[i] == '%')
		{
			len++;
			i++;
		}
	}
	while (s[i++] != '%' && s[i] != '\0')
		len++;
	return len;
}

static int	count_ap(char const *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i++])
	{
		if (s[i] == '%')
		{
			count++;
			if (s[i + 1] == '%')
				i++;
		}
	}
	return count;
}

t_format	ft_split_format(char const *format)
{
	t_format info_f;
	int i;
	int j;

	i = 0;
	info_f.nb_ap = 0;
	if ((info_f.str = malloc(sizeof(char *) * count_ap(format) + 1)) == NULL)
		return info_f;
	while (format[i])
	{
		j = 0;
		if ((info_f.str[info_f.nb_ap] = malloc(sizeof(char) * ft_seglen(format, i) + 1)) == NULL)
			return info_f;
		if (format[i] == '%')
		{
			info_f.str[info_f.nb_ap][j++] = format[i++];
			if (format[i] == '%')
				info_f.str[info_f.nb_ap][j++] = format[i++];
		}
		while (format[i] != '%' && format[i] != '\0')
			info_f.str[info_f.nb_ap][j++] = format[i++];
		info_f.str[info_f.nb_ap++][j] = '\0';
	}
	info_f.str[info_f.nb_ap] = NULL;
	return info_f;
}
