/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:40:09 by lucocozz          #+#    #+#             */
/*   Updated: 2020/01/30 10:46:44 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_rigth_padding(char *str, t_flags f, char *ad, int nb)
{
	int	i;
	int	to_write;

	i = 0;
	to_write = ft_strlen(ad);
	str = ft_setchar_decfw(str, &i, &f, '0');
	str = ft_setchar_decfw(str, &i, &f, 'x');
	while ((f.hp && f.p) > to_write)
	{
		str = ft_setchar_decfw(str, &i, &f, '0');
		f.p--;
	}
	if (nb || (f.hp && f.p) || !f.w)
		while (*ad)
		{
			ft_setchar_decfw(str, &i, &f, *ad);
			ad++;
		}
	while (f.w > 0)
		ft_setchar_decfw(str, &i, &f, ' ');
	return (str);
}

static char	*ft_left_padding(char *str, t_flags f, char *ad, int nb)
{
	int	i;
	int	to_write;

	i = 0;
	to_write = ft_strlen(ad);
	while (f.w > to_write + 2 && (f.w > f.p + 2 && f.hp))
		ft_setchar_decfw(str, &i, &f, (f.w && !f.hp ? ' ' : '0'));
	str = ft_setchar_decfw(str, &i, &f, '0');
	str = ft_setchar_decfw(str, &i, &f, 'x');
	while (f.p > to_write && f.hp)
	{
		ft_setchar_decfw(str, &i, &f, '0');
		f.p--;
	}
	if (nb || (f.hp && f.p) || !f.w)
		while (*ad)
		{
			ft_setchar_decfw(str, &i, &f, *ad);
			ad++;
		}
	return (str);
}

char		*ft_p(va_list ap, t_flags f)
{
	char		*ad;
	char		*str;
	uintptr_t	nb;
	int			len;

	nb = (uintptr_t)va_arg(ap, void*);
	ad = ft_ltoa_base((long)nb, "0123456789abcdef");
	len = ft_strlen(ad);
	str = ft_calloc(f.w + f.p + len + 1, sizeof(char));
	if (f.j)
		str = ft_rigth_padding(str, f, ad, nb);
	else
		str = ft_left_padding(str, f, ad, nb);
	ft_strdel(ad);
	return (str);
}
