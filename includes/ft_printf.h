/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:33:12 by lucocozz          #+#    #+#             */
/*   Updated: 2019/10/31 17:33:14 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define PARAMS "%sSpdDioOuUxXcC"
# define NBPARAM ft_strlen(PARAMS)
# define LENPARAM 3

//%o = ft_uitoa_base(nb, base); (base 8)
//%u = ft_uitoa_base(nb, base); (base 10)
//%X = ft_uitoa_base(nb, base); (base 16)
//%x = ft_lowercase(ft_uitoa_base(nb, base)); (base 16)
//%d,i = ft_itoa(nb);
//%sS = ft_putstr(str);
//%cC = ft_putchar(c);
//%% = ft_putchar('%');

typedef struct	s_format
{
	char		**str;
	int			nb_ap;
	va_list		ap;
}				t_format;

int				ft_printf(const char *format, ... );
t_format		ft_split_format(char const *format);
int				ft_detect_format(t_format info_f, int i);
char			*ft_uitoa_base(unsigned int nb, int base);

#endif
