/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:33:36 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/28 17:57:20 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t i;
	size_t tdest;

	tdest = 0;
	while (dest[tdest] && tdest < dstsize)
		tdest++;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize == tdest)
		return (ft_strlen(src) + dstsize);
	i = 0;
	while (src[i] && (tdest + i) < dstsize - 1)
	{
		dest[tdest + i] = src[i];
		i++;
	}
	dest[tdest + i] = '\0';
	return (tdest + ft_strlen(src));
}
