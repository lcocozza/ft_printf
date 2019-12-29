/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:39:40 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/26 14:19:59 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char	*mem = ft_strdup("suce pute");
	int		len;
	
	len = ft_printf("%.4d", 42);
	printf("|\n");
	printf("len=%d\n", len);
	len = printf("%.4d", 42);
	printf("|\n");
	printf("len=%d\n", len);
	free(mem);
	return (0);
}
