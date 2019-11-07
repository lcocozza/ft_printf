/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:13:33 by lucocozz          #+#    #+#             */
/*   Updated: 2019/11/02 17:13:33 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_len(long n, int base)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(int n, int base)
{
	int		i;
	char	*strnew;

	i = ft_number_len(n, base);
	if ((strnew = ft_calloc(i + 1, sizeof(char))) == NULL)
		return (NULL);
	strnew[i--] = '\0';
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		strnew[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		strnew[i] = (n % base) + '0';
		n /= base;
		i--;
	}
	return (strnew);
}
