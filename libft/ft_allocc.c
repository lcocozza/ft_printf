/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:04:32 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/29 16:25:30 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_allocc(size_t count, size_t size, int c)
{
	int		t_size;
	void	*tmp;

	t_size = count * size;
	if ((tmp = malloc(t_size)) == NULL)
		return (NULL);
	ft_bzero(tmp, t_size);
	ft_memset(tmp, c, t_size - 1);
	return (tmp);
}
