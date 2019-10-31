/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:13:19 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/28 14:27:09 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptrd;
	unsigned char	*ptrs;
	size_t			i;

	ptrd = (unsigned char*)dest;
	ptrs = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		if (ptrd[i] == (unsigned char)c)
		{
			i++;
			return ((void*)(dest + i));
		}
		i++;
	}
	return (NULL);
}
