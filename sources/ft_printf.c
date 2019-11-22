/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:53:30 by lucocozz          #+#    #+#             */
/*   Updated: 2019/11/22 02:04:30 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_types 	g_types[TYPESLEN] = {
									{'%', &ft_per},
									{'c', &ft_c},
									{'s', &ft_s},
									{'p', &ft_p},
									{'d', &ft_d},
									{'i', &ft_i},
									{'u', &ft_u},
									{'x', &ft_x},
									{'X', &ft_xu}
													};


static char	*ft_get_flags(t_flags flags, va_list ap)
{
	int i;

	i = 0;
	ap = ap;
	while (i <= TYPESLEN && flags.type != g_types[i].name)
		i++;
	return (flags.type == g_types[i].name ? g_types[i].f(ap, flags) : ft_strdup("NA"));
}

static char	*ft_get_format(char **pt_arg, va_list ap)
{
	int			i;
	char		*arg;
	t_flags		flags;

	i = 0;
	ap = ap;
	arg = *pt_arg;
	printf("arg[i]=%c\n", arg[i]);
	while (ft_strchr(TYPES, arg[i]) == NULL && arg[i])
	{
		flags.flags = (arg[i] == '-' || arg[i] == '0' ? arg[i++] : '\0');
		
		if ((int)ft_strclen(TYPES, arg[i]) == -1)
			i++;
	}
	flags.type = arg[i];
	*pt_arg = &arg[i + 1];
	return (ft_get_flags(flags, ap));
}

static void	ft_format_string(char **buffer, char *param, char *arg)
{
	size_t	size;

	size = ft_strlen(*buffer) + ft_strlen(param) + ft_strlen(arg) + 1;
	*buffer = ft_srealloc(*buffer, size);
	ft_strcat(*buffer, param);
	ft_strcat(*buffer, arg);
	ft_strdel(param);
}

int			ft_printf(const char *format, ...)
{
	t_format	tmp;
	
	tmp.buffer = NULL;
	va_start(tmp.ap, format);
	tmp.arg = (char *)format;
	while ((tmp.i = ft_strclen(tmp.arg, '%')) != -1)
	{
		tmp.arg = &tmp.arg[tmp.i + 1];
		if (!tmp.buffer)
			tmp.buffer = ft_substr(format, 0, tmp.i);
		tmp.param = ft_get_format(&tmp.arg, tmp.ap);
		ft_format_string(&tmp.buffer, tmp.param, tmp.arg);
	}
	va_end(tmp.ap);
	tmp.len = ft_lputstr((tmp.buffer ? tmp.buffer : format));
	ft_strdel(tmp.buffer);
	return (tmp.len);
}
