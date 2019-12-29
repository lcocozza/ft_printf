/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 17:54:12 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/29 18:24:14 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_set_p(char *nb, int p)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(nb) - (nb[0] == '-' ? 1 : 0);
	if (p > len)
	{
		new = ft_allocc(p + 1, sizeof(char), '0');
		if (nb[0] == '-')
			new[i++] = *nb++;
		while (p--)
		{
			if (p <= i)
			{
				new[i] = *nb;
				*nb++;
			}
			i++;
		}
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
	f.w = (f.w <= len ? 0 : f.w - len);
	nb = ft_set_p(nb, f.p);
	printf("len=%d\n", len);
	str = ft_allocc((f.w ? f.w : len) + 1, sizeof(char), (f.z ? '0' : ' '));
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
