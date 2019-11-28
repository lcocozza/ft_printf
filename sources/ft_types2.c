/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 02:59:52 by lucocozz          #+#    #+#             */
/*   Updated: 2019/11/26 18:23:14 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_u(va_list ap, t_flags flags)
{
	unsigned int	nb;

	(void)flags;
	nb = va_arg(ap, unsigned int);
	return (ft_uitoa(nb));
}

char	*ft_x(va_list ap, t_flags flags)
{
	int	nb;

	(void)flags;
	nb = va_arg(ap, int);
	return (ft_itoa_base(nb, "0123456789abcdef"));
}

char	*ft_xu(va_list ap, t_flags flags)
{
	int	nb;

	(void)flags;
	nb = va_arg(ap, int);
	return (ft_itoa_base(nb, "0123456789ABCDEF"));
}

char	*ft_per(va_list ap, t_flags flags)
{
	(void)ap;
	(void)flags;
	return (ft_strdup("%"));
}
