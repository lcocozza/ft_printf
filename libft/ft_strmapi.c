/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:41:44 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/10 22:28:29 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*strnew;

	i = 0;
	if (!s || !f)
		return (NULL);
	if ((strnew = ft_calloc(ft_strlen(s) + 1, sizeof(char))) == NULL)
		return (NULL);
	while (s[i])
	{
		strnew[i] = f(i, s[i]);
		i++;
	}
	return (strnew);
}
