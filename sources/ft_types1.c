/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:54:12 by lucocozz          #+#    #+#             */
/*   Updated: 2019/11/22 03:17:14 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_c(va_list ap, t_flags flags)
{
	char	c;

	flags = flags;
	c = (char)va_arg(ap, int);
	return (ft_strdup(&c));
}

char	*ft_s(va_list ap, t_flags flags)
{
	char	*str;
	
	str = va_arg(ap, char*);
	if (str == NULL)
		return (ft_strdup("(null)"));
	flags = flags;
	return (ft_strdup(str));
}

char	*ft_p(va_list ap, t_flags flags)
{
	// void	*ptr;

	ap = ap;
	flags = flags;
	// ptr = va_arg(ap, void*);
	// return (ft_itoa_base((int)&ptr, "012346789abcdef"));
	return (ft_strdup("0x0"));
}

char	*ft_d(va_list ap, t_flags flags)
{
	int	nb;

	flags = flags;
	nb = va_arg(ap, int);
	return (ft_itoa(nb));
}

char	*ft_i(va_list ap, t_flags flags)
{
	int	nb;

	flags = flags;
	nb = va_arg(ap, int);
	return (ft_itoa(nb));
}

