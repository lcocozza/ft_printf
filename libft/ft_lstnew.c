/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:10:08 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/11 14:13:02 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *elem;

	if ((elem = malloc(sizeof(t_list) * 1)) == NULL)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
