/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:53:30 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/04 17:28:47 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_types		g_types[N_TYPES] = {
	{'%', &ft_per}, {'c', &ft_c}, {'s', &ft_s},
	{'p', &ft_p}, {'d', &ft_d}, {'i', &ft_i},
	{'u', &ft_u}, {'x', &ft_x}, {'X', &ft_xu}
};

static void		ft_format_buffer(t_parse data, t_buffer *buffer, va_list ap)
{
	int	i;

	i = 0;
	while (i <= N_TYPES && data.type != g_types[i].name)
		i++;
	g_types[i].function(ap, data, buffer);
}

static t_parse	ft_parsing(const char *format, int *i, va_list ap)
{
	t_parse	data;

	data = ft_init_parse();
	*i += 1;
	while (!ft_strchr(TYPES, format[*i]) && format[*i])
	{
		*i += ft_parse_padding(format[*i], &data);
		*i += ft_parse_fill(format[*i], &data);
		*i += ft_parse_width(&format[*i], &data, ap);
		*i += ft_parse_precision(&format[*i], &data, ap);
	}
	data.type = format[*i];
	*i += 1;
	return (data);
}

int				ft_printf(const char *format, ...)
{
	int			i;
	t_buffer	buffer;
	va_list		ap;

	i = 0;
	buffer.i = 0;
	buffer.len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			ft_format_buffer(ft_parsing(format, &i, ap), &buffer, ap);
		else
			ft_insert_in_buffer(&buffer, format[i++]);
	}
	ft_print_buffer(&buffer);
	return (buffer.len);
}
