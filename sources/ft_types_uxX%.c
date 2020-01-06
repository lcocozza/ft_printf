/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_uxX%.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:59:52 by lucocozz          #+#    #+#             */
/*   Updated: 2020/01/06 15:35:39 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_u(va_list ap, t_flags f)
{
	int		n;
	int		len;
	char	*nb;
	char	*str;

	n = va_arg(ap, int);
	nb = ft_uitoa(n);
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

char	*ft_x(va_list ap, t_flags f)
{
	int		n;
	int		len;
	char	*nb;
	char	*str;

	n = va_arg(ap, int);
	nb = ft_uitoa_base(n, "0123456789abcdef");
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

char	*ft_xu(va_list ap, t_flags f)
{
	return (ft_strupper(ft_x(ap, f)));
}

char	*ft_per(va_list ap, t_flags f)
{
	(void)ap;
	(void)f;
	return (ft_strdup("%"));
}
