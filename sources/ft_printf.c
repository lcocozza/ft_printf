/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:53:30 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/09 01:21:32 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_types g_types[TYPESLEN] = {
	{'%', &ft_per}, {'c', &ft_c}, {'s', &ft_s},
	{'p', &ft_p}, {'d', &ft_d}, {'i', &ft_i},
	{'u', &ft_u}, {'x', &ft_x}, {'X', &ft_xu}
};

static t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.j = 0;
	flags.z = 0;
	flags.w = 0;
	flags.p = 0;
	flags.t = 0;
	flags.f = 0;
	flags.hp = 0;
	return (flags);
}

static char		*ft_get_flags(t_flags flags, va_list ap)
{
	int i;

	i = 0;
	while (i <= TYPESLEN && flags.t != g_types[i].name)
		i++;
	return (g_types[i].f(ap, flags));
}

static char		*ft_get_format(char **pt_arg, va_list ap)
{
	int			i;
	char		*arg;
	t_flags		flags;

	i = 0;
	arg = *pt_arg;
	flags = ft_init_flags();
	while (ft_strchr(TYPES, arg[i]) == NULL && arg[i])
	{
		i += ft_justify(&arg[i], &flags);
		i += ft_zero(&arg[i], &flags);
		i += ft_width(&arg[i], &flags, ap);
		i += ft_precision(&arg[i], &flags, ap);
	}
	flags.f = (arg[i - 1] != '%' ? 1 : 0);
	flags.t = arg[i];
	*pt_arg = &arg[i + 1];
	return (ft_get_flags(flags, ap));
}

int				ft_printf(const char *format, ...)
{
	t_format	tmp;
	char		*to_free;

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
		to_free = tmp.buff;
		tmp.buff = ft_strscat(3, to_free, tmp.param, tmp.arg);
		free(to_free);
		ft_strdel(tmp.param);
	}
	va_end(tmp.ap);
	tmp.len = ft_lputstr((tmp.buff ? tmp.buff : format));
	ft_strdel(tmp.buff);
	return (tmp.len);
}
