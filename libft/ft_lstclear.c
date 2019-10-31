/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:02:32 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/11 16:07:01 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *prev;
	t_list *curr;

	curr = *lst;
	while (curr)
	{
		(*del)(curr->content);
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	*lst = NULL;
}
