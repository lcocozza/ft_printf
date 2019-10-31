.SILENT:

NAME= libftprintf.a

SRCS_FILE=	ft_split_format.c	ft_format.c			ft_convert.c		\
			ft_printf.c

LIBFT_FILE=	ft_memset.c			ft_bzero.c			ft_memcpy.c			\
			ft_memccpy.c	 	ft_memmove.c 		ft_memchr.c			\
			ft_memcmp.c 		ft_strlen.c 		ft_strdup.c			\
			ft_strlcpy.c	 	ft_strlcat.c 		ft_strchr.c			\
			ft_strrchr.c 		ft_strnstr.c 		ft_strncmp.c		\
			ft_atoi.c 			ft_isalpha.c 		ft_isdigit.c		\
			ft_isalnum.c	 	ft_isascii.c 		ft_isprint.c		\
			ft_toupper.c 		ft_tolower.c 		ft_strmapi.c		\
			ft_strjoin.c 		ft_strtrim.c 		ft_split.c			\
			ft_itoa.c 			ft_putchar_fd.c 	ft_putstr_fd.c		\
			ft_putendl_fd.c 	ft_putnbr_fd.c		ft_calloc.c			\
			ft_substr.c			ft_lstnew.c			ft_lstadd_front.c	\
			ft_lstsize.c 		ft_lstlast.c		ft_lstadd_back.c 	\
			ft_lstdelone.c		ft_lstclear.c 		ft_lstiter.c		\

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
