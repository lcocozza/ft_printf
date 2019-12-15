/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:54:12 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/15 06:58:25 by lucocozz         ###   ########.fr       */
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
	str = ft_calloc(f.w + len, sizeof(char));
	ft_memset(str, ' ', f.w + len);
	ft_memcpy((f.j ? str : &str[f.w]), s, len);
	return (str);
}

char	*ft_p(va_list ap, t_flags flags)
{
	char	*addr;
	char	*hex;
	void	*pt;
	int		len;

	pt = va_arg(ap, void*);
	if (pt == NULL)
		hex = ft_strdup("0x0");
	else
		hex = ft_strfjoinp(ft_ltoa_base((long)pt, "0123456789abcdef"), "0x", 1);
	len = ft_strlen(hex);
	if (len < flags.w)
	{
		addr = ft_calloc(flags.w + 1, sizeof(char));
		ft_strcpy((flags.j ? addr : &addr[flags.w - len]), hex);
		ft_memset((flags.j ? &addr[len] : addr), ' ', flags.w - len);
		free(hex);
		return (addr);
	}
	return (hex);
}

char	*ft_d(va_list ap, t_flags flags)
{
	int	nb;

	(void)flags;
	nb = va_arg(ap, int);
	return (ft_itoa(nb));
}

char	*ft_i(va_list ap, t_flags flags)
{
	int	nb;

	(void)flags;
	nb = va_arg(ap, int);
	return (ft_itoa(nb));
}
