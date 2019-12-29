/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:30:28 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/16 06:00:35 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_justify(char *s, t_flags *flags)
{
	flags->j = (s[0] == '-' ? 1 : 0);
	if (s[0] == '-')
		flags->z = 0;
	return (s[0] == '-' ? 1 : 0);
}

int	ft_zero(char *s, t_flags *flags)
{
	if (s[0] == '0' && !flags->j)
		flags->z = 1;
	else
		flags->z = 0;
	return (s[0] == '0' ? 1 : 0);
}

int	ft_width(char *s, t_flags *flags, va_list ap)
{
	int	i;

	i = 0;
	if (s[0] == '*')
	{
		flags->w = va_arg(ap, int);
		i++;
	}
	else
	{
		flags->w = ft_atoui(s);
		while (ft_isdigit(s[i]))
			i++;
	}
	return (i);
}

int	ft_precision(char *s, t_flags *flags, va_list ap)
{
	int	i;

	i = 0;
	if (s[i] == '.')
	{
		i++;
		flags->hp = 1;
		if (s[i] == '*')
		{
			flags->p = va_arg(ap, int);
			i++;
		}
		else
			flags->p = ft_atoui(&s[i]);
		while (ft_isdigit(s[i]))
			i++;
	}
	else
		flags->hp = 0;
	return (i);
}
