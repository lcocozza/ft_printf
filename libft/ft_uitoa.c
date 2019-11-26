/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:46:15 by lucocozz          #+#    #+#             */
/*   Updated: 2019/11/22 20:50:03 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_uitoa(unsigned int n)
{
	unsigned int	i;
	char			*strnew;

	i = ft_nbrlen(n, 10);
	if ((strnew = ft_calloc(i + 1, sizeof(char))) == NULL)
		return (NULL);
	strnew[i--] = '\0';
	if (n == 0)
		return (ft_strdup("0"));
	while (n > 0)
	{
		strnew[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (strnew);
}

