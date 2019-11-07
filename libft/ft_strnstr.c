/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:30:57 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/31 17:46:06 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *chr, size_t len)
{
	size_t place;
	size_t i;

	if (chr[0] == '\0')
		return ((char*)str);
	place = 0;
	while (str[place] != '\0' && place < len)
	{
		if (str[place] == chr[0])
		{
			i = 1;
			while (chr[i] != '\0' && str[place + i] == chr[i] &&
					(place + i) < len)
				++i;
			if (chr[i] == '\0')
				return ((char*)&str[place]);
		}
		place++;
	}
	return (0);
}
