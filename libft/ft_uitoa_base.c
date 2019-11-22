/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 03:28:55 by lucocozz          #+#    #+#             */
/*   Updated: 2019/11/22 03:39:34 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa_base(unsigned int n, char const *base)
{
	unsigned int	len;
	unsigned int	div;
	char			*output;
	unsigned int	i;
	unsigned int	base_val;

	base_val = ft_strlen(base);
	div = 1;
	len = 1;
	while (n / div > base_val - 1)
	{
		len++;
		div *= base_val;
	}
	if ((output = ft_calloc(len, sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	while (div)
	{
		output[i++] = base[(n / div) % base_val];
		div /= base_val;
	}
	return (output);
}
