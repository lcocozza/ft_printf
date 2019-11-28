/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:54:12 by lucocozz          #+#    #+#             */
/*   Updated: 2019/11/28 20:58:40 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_c(va_list ap, t_flags flags)
{
	char	*str;

	str = ft_calloc(flags.w, sizeof(char));
	if (flags.j)
	{
		str[0] = (char)va_arg(ap, int);
		ft_memset(&str[1], ' ', flags.w - 1);
	}
	else
	{
		ft_memset(str, ' ', flags.w - 1);
		str[flags.w - 1] = (char)va_arg(ap, int);
	}
	return (str);
}

char	*ft_s(va_list ap, t_flags flags)
{
	char	*s;
	char	*str;
	int		len;

	s = va_arg(ap, char*);
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (len < flags.w)
	{
		str = ft_calloc(flags.w + 1, sizeof(char));
		ft_strcpy((flags.j ? str : &str[flags.w - len]), s);
		ft_memset((flags.j ? &str[len] : str), ' ', flags.w - len);
		return (str);
	}
	return (ft_strdup(s));
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
