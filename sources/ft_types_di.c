/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:54:12 by lucocozz          #+#    #+#             */
/*   Updated: 2020/01/06 15:24:06 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char		*ft_set_p(char *nb, int p)
{
	char	*new;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(nb) - (nb[0] == '-' ? 1 : 0);
	if (p > len)
	{
		new = ft_allocc(p + (nb[0] == '-' ? 2 : 1), sizeof(char), '0');
		if (nb[0] == '-')
			new[i++] = nb[j++];
		i += p - len;
		while (nb[j])
			new[i++] = nb[j++];
		free(nb);
		return (new);
	}
	return (nb);
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
	if (f.hp && f.p <= len)
		f.hp = 0;
	else if (f.hp)
		len = f.p;
	nb = ft_set_p(nb, f.p);
	len = ft_strlen(nb);
	f.w = (f.w <= len ? 0 : f.w - len);
	str = ft_allocc(f.w + len + 1, sizeof(char), (f.z ? '0' : ' '));
	if (f.j)
		ft_memcpy(str, nb, len);
	else
		ft_memcpy(&str[f.w], nb, len);
	ft_strdel(nb);
	return (str);
}

char		*ft_i(va_list ap, t_flags f)
{
	return (ft_d(ap, f));
}
