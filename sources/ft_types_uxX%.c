/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_uxX%.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:59:52 by lucocozz          #+#    #+#             */
/*   Updated: 2020/01/08 18:09:58 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_u(va_list ap, t_flags f)
{
	int		n;
	char	*nb;

	n = va_arg(ap, int);
	nb = ft_uitoa(n);
	nb = ft_format_nb(f, nb);
	return (nb);
}

char	*ft_x(va_list ap, t_flags f)
{
	int		n;
	char	*nb;

	n = va_arg(ap, int);
	nb = ft_uitoa_base(n, "0123456789abcdef");
	nb = ft_format_nb(f, nb);
	return (nb);
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
