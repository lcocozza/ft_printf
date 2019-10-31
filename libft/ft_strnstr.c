/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:30:57 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/29 14:01:36 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t place;
	size_t i;

	if (little[0] == '\0')
		return ((char*)big);
	place = 0;
	while (big[place] != '\0' && place < len)
	{
		if (big[place] == little[0])
		{
			i = 1;
			while (little[i] != '\0' && big[place + i] == little[i] &&
					(place + i) < len)
				++i;
			if (little[i] == '\0')
				return ((char*)&big[place]);
		}
		place++;
	}
	return (0);
}
