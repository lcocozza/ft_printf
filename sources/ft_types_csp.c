/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_csp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:54:12 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/29 17:54:36 by lucocozz         ###   ########.fr       */
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
	s = (!s ? "(null)" : s);
	len = ft_strlen(s);
	if (f.hp && f.p >= len)
		f.hp = 0;
	else if (f.hp)
		len = f.p;
	f.w = (f.w <= len ? 0 : f.w - len);
	str = ft_calloc((f.w ? f.w : len) + 1, sizeof(char));
	ft_memset(str, ' ', f.w + len);
	ft_memcpy((f.j ? str : &str[f.w]), s, len);
	return (str);
}

char	*ft_p(va_list ap, t_flags f)
{
	char	*ad;
	char	*str;
	void	*pt;
	int		len;

	pt = va_arg(ap, void*);
	if (pt == NULL)
		ad = ft_strdup(f.hp ? "0x" : "0x0");
	else
		ad = ft_strfjoinp(ft_ltoa_base((long)pt, "0123456789abcdef"), "0x", 1);
	len = ft_strlen(ad);
	f.w = (f.w <= len ? 0 : f.w - len);
	str = ft_calloc((f.w ? f.w : len) + 1, sizeof(char));
	ft_memset(str, ' ', f.w);
	if (f.j)
		ft_memcpy(str, ad, len);
	else
		ft_memcpy(&str[f.w], ad, len);
	ft_strdel(ad);
	return (str);
}
