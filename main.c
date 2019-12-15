/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:39:40 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/15 06:58:51 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char	*mem = ft_strdup("suce pute");
	int		len;
	
	len = ft_printf("%34.2s", mem);
	printf("|\n");
	printf("len=%d\n", len);
	len = printf("%34.2s", mem);
	printf("|\n");
	printf("len=%d\n", len);
	free(mem);
	return (0);
}
