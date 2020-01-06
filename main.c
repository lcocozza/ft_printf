/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:39:40 by lucocozz          #+#    #+#             */
/*   Updated: 2020/01/06 15:44:50 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char	*mem = ft_strdup("suce pute");
	int		len;
	
	len = 0;
	len = ft_printf("%-6.4X", 42);
	printf("|\n");
	printf("len=%d\n", len);
	len = printf("%-6.4X", 42);
	printf("|\n");
	printf("len=%d\n", len);
	free(mem);
	return (0);
}
