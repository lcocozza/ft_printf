/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:19:43 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/29 13:58:41 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t len;

	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == (char)c)
			return ((char*)&s[len]);
		len--;
	}
	if (s[0] == c)
		return ((char*)s);
	return (NULL);
}
