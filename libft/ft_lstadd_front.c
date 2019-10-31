/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:13:21 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/11 14:17:33 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list *elem;
	t_list *tmp;

	tmp = *alst;
	if (!tmp)
		*alst = new;
	else
	{
		elem = new;
		elem->next = tmp;
		*alst = elem;
	}
}
