/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:33:12 by lucocozz          #+#    #+#             */
/*   Updated: 2019/11/22 20:10:48 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define TYPES "cspdiuxX%"
# define FLAGS	"-0.*"
# define TYPESLEN 9

typedef struct	s_types
{
	char		name;
	char		*(*f)();
}				t_types;

typedef struct	s_flags
{
	char		flags;
	int			width;
	int			precision;
	char		type;
}				t_flags;

typedef struct	s_format
{
	int			i;
	int			len;
	char		*arg;
	char		*param;
	char		*buff;
	va_list 	ap_cpy;
	va_list		ap;
}				t_format;


int				ft_printf(const char *format, ...);
char			*ft_c(va_list ap, t_flags flags);
char			*ft_s(va_list ap, t_flags flags);
char			*ft_p(va_list ap, t_flags flags);
char			*ft_d(va_list ap, t_flags flags);
char			*ft_i(va_list ap, t_flags flags);
char			*ft_u(va_list ap, t_flags flags);
char			*ft_x(va_list ap, t_flags flags);
char			*ft_xu(va_list ap, t_flags flags);
char			*ft_per(va_list ap, t_flags flags);
											
#endif