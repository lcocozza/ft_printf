/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_csp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:54:12 by lucocozz          #+#    #+#             */
/*   Updated: 2020/01/28 11:40:43 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_c(va_list ap, t_flags f)
{
	int		i;
	char	c;
	char	*str;

	i = 0;
	c = (char)va_arg(ap, int);
	if (c)
	{
		str = ft_calloc(f.w + 2, sizeof(char));
		if (f.j)
		{
			str = ft_setchar_decfw(str, &i, &f, c);
			while (f.w > 0)
				str = ft_setchar_decfw(str, &i, &f, ' ');
		}
		else
		{
			while (f.w > 0)
				str = ft_setchar_decfw(str, &i, &f, (f.z ? '0' : ' '));
			str = ft_setchar_decfw(str, &i, &f, c);
		}
		return (str);
	}
	return (NULL);
}

static char	*ft_rigth_padding(char *buff, t_flags f, char *str)
{
	int	i;

	i = 0;
	if (!f.hp)
		while (*str)
		{
			buff[i++] = *str;
			str++;
			f.w--;
		}
	else
		while (*str && f.p > 0)
		{
			buff[i++] = *str;
			str++;
			f.w--;
		}
	while (f.w > 0)
	{
		buff[i++] = ' ';
		f.w--;
	}
	return (buff);
}

static char	*ft_left_padding(char *buff, t_flags f, char *str)
{
	int	i;
	int	len;

	i = 0;
	if (!f.hp)
		len = ft_strlen(str);
	else
		len = ((int)ft_strlen(str) < f.p ? (int)ft_strlen(str) : f.p);
	while (f.w > len)
	{
		buff[i++] = (f.z ? '0' : ' ');
		f.w--;
	}
	while (len > 0)
	{
		buff[i++] = *str;
		str++;
		len--;
	}
	return (buff);
}

char	*ft_s(va_list ap, t_flags f)
{
	char	*s;
	char	*str;
	int		len;

	s = va_arg(ap, char*);
	len = ft_strlen(s);
	if (f.p < 0)
		f.p = len;
	if (s[0] == '\0' || (!f.w && !f.p && f.hp))
		return (NULL);
	s = (!s ? "(null)" : s);
	str = ft_calloc(f.w + f.p + len + 1, sizeof(char));
	if (f.j)
		str = ft_rigth_padding(str, f, s);
	else
		str = ft_left_padding(str, f, s);
	return (str);
}
