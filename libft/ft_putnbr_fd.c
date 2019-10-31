/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 17:50:56 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/10 17:37:18 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_nb(int nb, int fd)
{
	if (nb > 0)
	{
		ft_print_nb(nb / 10, fd);
		ft_putchar_fd(nb % 10 + '0', fd);
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == 0)
		ft_putchar_fd('0', fd);
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb == -2147483648)
	{
		ft_putchar_fd('2', fd);
		nb = 147483648;
	}
	ft_print_nb(nb, fd);
}
