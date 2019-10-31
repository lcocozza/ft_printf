/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:26:16 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/26 16:36:44 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*elem;
	t_list	*lstnew;

	if (!f || !del)
		return (NULL);
	lstnew = NULL;
	while (lst)
	{
		if ((elem = ft_lstnew((*f)(lst->content))) == NULL)
		{
			ft_lstclear(&lstnew, del);
			return (NULL);
		}
		ft_lstadd_back(&lstnew, elem);
		lst = lst->next;
	}
	return (lstnew);
}
