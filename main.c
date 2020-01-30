/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:39:40 by lucocozz          #+#    #+#             */
/*   Updated: 2020/01/18 02:39:09 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char	*mem = ft_strdup("%%");
	int		len;
	
	len = 0;
	len = ft_printf("%*s|\n", -4, mem);
	printf("len=%d\n", len);
	len = printf("%*s|\n", -4, mem);
	printf("len=%d\n", len);
	free(mem);
	return (0);
}
