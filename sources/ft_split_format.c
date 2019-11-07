/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:36:01 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/31 17:37:56 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_seglen(char const *s, int i)
{
	int len;

	len = 0;
	if (s[i] == '%')
	{
		len++;
		i++;
	}
	while (!(ft_strfind_c(PARAMS, s[i])) && s[i++])
		len++;
	return (++len);
}

static int	count_ap(char const *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i++])
	{
		if (s[0] != '%')
			count++;
		if (s[i] == '%')
		{
			count++;
			while (!(ft_strfind_c(PARAMS, s[i])) && s[i++])
				;
		}
	}
	return (count);
}

t_format	ft_split_format(char const *format)
{
	t_format	info_f;
	int			i;
	int			j;

	i = 0;
	info_f.nb_ap = 0;
	info_f.str = malloc(sizeof(char *) * count_ap(format) + 1);
	while (format[i])
	{
		j = 0;
		info_f.str[info_f.nb_ap] = malloc(sizeof(char) * ft_seglen(format, i) + 1);
		if (format[i] == '%')
		{
			info_f.str[info_f.nb_ap][j++] = format[i++];
			while (!(ft_strfind_c(PARAMS, format[i])) && format[i])
				info_f.str[info_f.nb_ap][j++] = format[i++];
			info_f.str[info_f.nb_ap][j++] = format[i++];
		}
		else
			while (format[i] != '%' && format[i] != '\0')
				info_f.str[info_f.nb_ap][j++] = format[i++];
		info_f.str[info_f.nb_ap++][j] = '\0';
	}
	info_f.str[info_f.nb_ap] = NULL;
	return (info_f);
}
