.SILENT:

NAME= libftprintf.a

SRC_NAME=	ft_printf.c \

LIB_NAME=	ft_putstr.c \
		ft_putnbr.c \
		ft_putchar.c \
		ft_strlen.c

OBJ_NAME= $(SRC_NAME:.c=.o) $(LIB_NAME:.c=.o)

SRC_PATH= srcs/
OBJ_PATH= objs/
LIB_PATH= libs/
INC_PATH= -I incls/

SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIB= $(addprefix $(LIB_PATH), $(LIB_NAME))

FLAGS= -Wall -Wextra -Werror

$(NAME): all

all:
	gcc $(FLAGS) -c $(SRC) $(LIB) $(INC_PATH) 
	mv $(OBJ_NAME) $(OBJ_PATH)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
