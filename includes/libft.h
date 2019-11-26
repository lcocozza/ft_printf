/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:37:23 by lucocozz          #+#    #+#             */
/*   Updated: 2019/11/25 16:49:57 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

void				*ft_memset(void *s, int c, size_t n);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
int					ft_nbrlen(long n, int base);
void				ft_strdel(char *s);
size_t				ft_strclen(const char *s, char c);
void				ft_swap(void **pt1, void **pt2);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
char				*ft_strstr(const char *big, const char *little);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcat(char *dest, char *src);
char				*ft_strscat(size_t size, ...);
char				*ft_strcpy(char *dest, char *src);
int					ft_atoi(const char *str);
char				*ft_itoa_base(int value, char *base);
char				*ft_uitoa_base(unsigned int n, char const *base);
int					ft_atoi_base(char *str, char *base);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isspace(int c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strfjoin(char *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_uitoa(unsigned int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
int					ft_lputstr(char const *s);
void				ft_putnbr(int n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_realloc(void *ptr, size_t size);
char				*ft_srealloc(char *str, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_subfstr(char *s, unsigned int start, size_t len);
int					ft_count_word(const char *str);
int					get_next_line(int fd, char **line);

#endif
