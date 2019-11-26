/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subfstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:33:44 by lucocozz          #+#    #+#             */
/*   Updated: 2019/11/22 19:46:44 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_subfstr(char *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((substr = ft_calloc(len + 1, sizeof(char))) == NULL)
		return (NULL);
	if (start < ft_strlen(s))
		while (i < len && s[start + i])
		{
			substr[i] = s[start + i];
			i++;
		}
	substr[i] = '\0';
	free(s);
	return (substr);
}
