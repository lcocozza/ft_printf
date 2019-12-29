/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:54:12 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/26 14:23:28 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_c(va_list ap, t_flags flags)
{
	char	c;
	char	*str;

	c = (char)va_arg(ap, int);
	if (c)
	{
		str = ft_calloc(flags.w, sizeof(char));
		ft_memset(str, ' ', flags.w);
		if (flags.j)
			str[0] = c;
		else
			str[(flags.w ? flags.w - 1 : 0)] = c;
		return (str);
	}
	return (ft_strdup(""));
}

char	*ft_s(va_list ap, t_flags f)
{
	char	*s;
	char	*str;
	int		len;

	s = va_arg(ap, char*);
	if (s[0] == '\0' || (!f.w && !f.p && f.hp))
		return (NULL);
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (f.p < 0)
		f.hp = 0;
	else if (f.hp && f.p >= len)
		f.hp = 0;
	else if (f.hp)
		len = f.p;
	if (f.w <= len)
		f.w = 0;
	else
		f.w -= len;
	str = ft_calloc(f.w + len + 1, sizeof(char));
	ft_memset(str, ' ', f.w + len);
	ft_memcpy((f.j ? str : &str[f.w]), s, len);
	return (str);
}

char	*ft_p(va_list ap, t_flags f)
{
	char	*addr;
	char	*str;
	void	*pt;
	int		len;

	pt = va_arg(ap, void*);
	if (pt == NULL)
		addr = ft_strdup("0x0");
	else
		addr = ft_strfjoinp(ft_ltoa_base((long)pt, "0123456789abcdef"), "0x", 1);
	len = ft_strlen(addr);
	if (f.w <= len)
		f.w = 0;
	else
		f.w -= len;
	str = ft_calloc(f.w + len + 1, sizeof(char));
	ft_memset(str, ' ', f.w + len);
	ft_memcpy((f.j ? str : &str[f.w]), addr, len);
	ft_strdel(addr);
	return (str);
}

char	*ft_d(va_list ap, t_flags f)
{
	int		n;
	int		len;
	char	*nb;
	char	*str;

	n = va_arg(ap, int);
	nb = ft_itoa(n);
	len = ft_strlen(nb);
	if (f.p < 0)
		f.hp = 0;
	else if (f.hp && f.p <= len)
		f.hp = 0;
	else if (f.hp)
		len = f.p;
	if (f.w <= len)
		f.w = 0;
	else
		f.w -= len;
	printf("len=%d\n", len);
	str = ft_allocc(f.w + len + 1, sizeof(char), '0');
	ft_memset(str, '0', f.w + len);
	ft_memcpy((f.j ? str : &str[f.w]), nb, len);
	ft_strdel(nb);
	return (str);
}

char	*ft_i(va_list ap, t_flags f)
{
	return (ft_d(ap, f));
}
