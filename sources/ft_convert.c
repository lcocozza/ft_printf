/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:33:27 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/31 17:34:23 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa_base(unsigned int nb, int base)
{
	char	*result;
	int		i;

	i = 0;
	result = ft_strnew(11);
	while (nb)
	{
		result[i] = (nb % base) + ((base == 16 && (nb % base) > 9) ? 55 : '0');
		nb /= base;
		i++;
	}
	return (ft_strrev(result));
}
