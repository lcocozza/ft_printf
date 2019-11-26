/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:53:30 by lucocozz          #+#    #+#             */
/*   Updated: 2019/11/25 18:41:51 by lucocozz         ###   ########.fr       */
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
	while (i <= TYPESLEN && flags.type != g_types[i].name)
		i++;
	return (g_types[i].f(ap, flags));
}

static char	*ft_get_format(char **pt_arg, va_list ap)
{
	int			i;
	char		*arg;
	t_flags		flags;

	i = 0;
	arg = *pt_arg;
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

int			ft_printf(const char *format, ...)
{
	t_format	tmp;
	
	tmp.buff = NULL;
	va_start(tmp.ap, format);
	tmp.arg = (char *)format;
	while ((tmp.i = ft_strclen(tmp.arg, '%')) != -1)
	{
		tmp.arg = &tmp.arg[tmp.i + 1];
		if (!tmp.buff)
			tmp.buff = ft_substr(format, 0, tmp.i);
		else
			tmp.buff = ft_subfstr(tmp.buff, 0, ft_strclen(tmp.buff, '%'));
		tmp.param = ft_get_format(&tmp.arg, tmp.ap);
		tmp.buff = ft_strscat(3, tmp.buff, tmp.param, tmp.arg);
		ft_strdel(tmp.param);
	}
	va_end(tmp.ap);
	tmp.len = ft_lputstr((tmp.buff ? tmp.buff : format));
	ft_strdel(tmp.buff);
	return (tmp.len);
}
