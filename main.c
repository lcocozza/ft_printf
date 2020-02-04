/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:39:40 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/04 16:42:58 by lucocozz         ###   ########.fr       */
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
	len = ft_printf("%*x\n", 3, uint);
	printf("len=%d\n", len);
	len = printf("%*x\n", 3, uint);
	printf("len=%d\n", len);
	// free(mem);
	return (0);
}
