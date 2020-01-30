/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:54:12 by lucocozz          #+#    #+#             */
/*   Updated: 2020/01/28 12:04:29 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_set_p(char *nb, t_flags f)
{
	char	*new;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(nb) - (nb[0] == '-' ? 1 : 0);
	if (f.p > len)
	{
		new = ft_allocc(f.p + (nb[0] == '-' ? 2 : 1), sizeof(char), '0');
		if (nb[0] == '-')
		{
			nb[i++] = (f.z && !f.hp ? '0' : ' ');
			j++;
		}
		i += f.p - len + (nb[0] == '-' ? 1 : 0);
		while (nb[j])
			new[i++] = nb[j++];
		free(nb);
		return (new);
	}
	else if (nb[0] == '-')
		nb[0] = (f.z && !f.hp ? '0' : ' ');
	return (nb);
}

char	*ft_set_neg(char *s)
{
	return (s);
}	

char		*ft_format_nb(t_flags f, char *nb)
{
	int		len;
	char	*str;
	int		neg;

	len = ft_strlen(nb);
	neg = (nb[0] == '-' ? 1 : 0);
	if (f.hp && f.p <= len)
		f.hp = 0;
	else if (f.hp)
		len = f.p;
	nb = ft_set_p(nb, f);
	len = ft_strlen(nb);
	f.w = (f.w <= len ? 0 : f.w - len);
	str = ft_allocc(f.w + len + 1, sizeof(char), f.z && !f.hp ? '0' : ' ');
	if (f.j)
		ft_memcpy(str, nb, len);
	else
		ft_memcpy(&str[f.w], nb, len);
	if (neg)
		str = ft_set_neg(str);
	ft_strdel(nb);
	return (str);
}

char	*ft_setchar_decfw(char *str, int *i, t_flags *f, char c)
{
	str[*i] = c;
	*i += 1;
	f->w--;
	return (str);
}

static char	*ft_right_padding(char *str, char *nb, t_flags f, int len)
{
	int	i;

	i = 0;
	if (*nb == '-')
	{
		str = ft_setchar_decfw(str, &i, &f, '-');
		nb++;
	}
	while (f.p > len)
	{
		str = ft_setchar_decfw(str, &i, &f, '0');
		f.p--;
	}
	if (*nb == '0' && (f.hp && !f.p) && f.w)
		str = ft_setchar_decfw(str, &i, &f, ' ');
	if (!(*nb == '0' && (f.hp && !f.p)))
		while (*nb)
		{
			str = ft_setchar_decfw(str, &i, &f, *nb);
			nb++;
		}
	while (f.w > 0)
		str = ft_setchar_decfw(str, &i, &f, ' ');
	return (str);
}

static char	*ft_left_padding(char *str, char *nb, t_flags f, int len)
{
	int	i;

	i = 0;
	if (*nb == '-' && f.z)
	{
		str = ft_setchar_decfw(str, &i, &f, '-');
		nb++;
	}
	while (f.w > len && f.w > f.p)
	{
		if (*nb == '-' && (f.w == len + 1 || f.w == f.p + 1))
			break;
		str = ft_setchar_decfw(str, &i, &f, (f.z
		|| (f.z && f.hp && f.p == 1) ? '0' : ' '));
	}
	if (*nb == '-' && !f.z)
	{
		str = ft_setchar_decfw(str, &i, &f, '-');
		nb++;
	}
	else if (*nb == '-' && f.w > len)
		str = ft_setchar_decfw(str, &i, &f, '0');
	if (f.hp)
		while (f.p > len)
		{
			str = ft_setchar_decfw(str, &i, &f, '0');
			f.p--;
		}
	if (*nb == '0' && (f.hp && !f.p) && f.w)
		str[i++] = ' ';
	if (!(*nb == '0' && f.hp && f.p == 0))
		while (*nb)
		{
			str[i++] = *nb;
			nb++;
		}
	return (str);
}


char		*ft_d(va_list ap, t_flags f)
{
	int		n;
	int		len;
	char	*nb;
	char	*str;

	n = va_arg(ap, int);
	nb = ft_itoa(n);
	len = ft_strlen(nb);
	if (f.p < 0)
		f.p = 1;
	str = ft_calloc(ABS(f.w + len + f.p) + 1, sizeof(char));
	if (f.j)
		str = ft_right_padding(str, nb, f, len - (n < 0 ? 1 : 0));
	else
		str = ft_left_padding(str, nb, f, len - (n < 0 ? 1 : 0));
	ft_strdel(nb);
	return (str);
}

char		*ft_i(va_list ap, t_flags f)
{
	return (ft_d(ap, f));
}
