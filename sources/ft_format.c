/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:34:35 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/31 17:35:47 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	**init_liste(void)
{
	char	**liste;
	char	param[NBPARAM];
	size_t	i;

	i = 0;
	liste = malloc(sizeof(char *) * (NBPARAM + 1));
	while (i < NBPARAM)
		liste[i++] = malloc(sizeof(char) * LENPARAM);
	i = 0;
	ft_strcpy(param, PARAMS);
	while (i < NBPARAM - 1)
	{
		liste[i][0] = '%';
		liste[i][1] = param[i];
		liste[i][2] = '\0';
		i++;
	}
	liste[i] = NULL;
	return (liste);
}

int			ft_detect_format(t_format info_f, int i)
{
	char	**liste;
	int		j;

	j = 0;
	liste = init_liste();
	while (liste[j])
		if (ft_strfind(info_f.str[i], liste[j++]))
			return (j - 1);
	return (-1);
}
