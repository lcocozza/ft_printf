/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:39:40 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/04 17:36:42 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	// char	*mem = ft_strdup("%%");
	int		len;
	unsigned int uint;
	
	uint = 4294967284;
	len = 0;
	len = ft_printf("%d\n", -2147483648);
	printf("len=%d\n", len);
	len = printf("%d\n", -2147483647);
	printf("len=%d\n", len);
	// free(mem);
	return (0);
}
