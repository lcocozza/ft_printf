/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:33:12 by lucocozz          #+#    #+#             */
/*   Updated: 2020/01/06 15:24:23 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

# define TYPES "cspdiuxX%"
# define FLAGS	"-0.*"
# define TYPESLEN 9
# define UNSIGN(x)	(x < 0 ? 0 : x)
# define ABS(x)		(x < 0 ? x * -1 : x)

typedef struct	s_types
{
	char		name;
	char		*(*f)();
}				t_types;

typedef struct	s_flags
{
	int			j;
	int			z;
	int			w;
	int			p;
	int			hp;
	char		t;
}				t_flags;

typedef struct	s_format
{
	int			i;
	int			len;
	char		*arg;
	char		*param;
	char		*buff;
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
int				ft_zero(char *s, t_flags *flags);
int				ft_justify(char *s, t_flags *flags);
int				ft_width(char *s, t_flags *flags, va_list ap);
int				ft_precision(char *s, t_flags *flags, va_list ap);
char			*ft_set_p(char *nb, int p);


											
#endif