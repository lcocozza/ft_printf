#.SILENT:

NAME= libftprintf.a

SRCS_FILE=	ft_printf.c			ft_types1.c			ft_types2.c		\
			ft_flags.c

LIBFT_FILE=	ft_memset.c			ft_bzero.c			ft_memcpy.c		\
			ft_memccpy.c	 	ft_memmove.c 		ft_memchr.c		\
			ft_memcmp.c 		ft_strlen.c 		ft_strdup.c		\
			ft_strchr.c			ft_strclen.c		ft_swap.c		\
			ft_strrchr.c 		ft_strstr.c 		ft_strcmp.c		\
			ft_atoi.c 			ft_isalpha.c 		ft_isdigit.c	\
			ft_isalnum.c	 	ft_isascii.c 		ft_isprint.c	\
			ft_toupper.c 		ft_tolower.c 		ft_strmapi.c	\
			ft_strjoin.c 		ft_strtrim.c 		ft_split.c		\
			ft_itoa.c 			ft_putchar.c 		ft_putstr.c		\
			ft_putnbr.c			ft_calloc.c			ft_substr.c		\
			get_next_line.c		ft_memdel.c			ft_srealloc.c	\
			ft_realloc.c		ft_lputstr.c		ft_strcat.c		\
			ft_strcpy.c			ft_strdel.c			ft_strfjoin.c	\
			ft_convert_base.c	ft_atoi_base.c		ft_itoa_base.c	\
			ft_uitoa_base.c		ft_strrev.c			ft_nbrlen.c		\
			ft_subfstr.c		ft_uitoa.c			ft_strscat.c	\
			ft_ltoa_base.c		ft_atoui.c			ft_isspace.c	\
			ft_strfjoinp.c


OBJS=	$(SRCS:.c=.o) $(LIBFT:.c=.o)

SRCS_PATH=	sources/
LIBFT_PATH=	libft/

SRCS=	$(addprefix $(SRCS_PATH), $(SRCS_FILE))
LIBFT=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

CC= gcc

CFLAGS= -Wall -Wextra -Werror -I includes/

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
