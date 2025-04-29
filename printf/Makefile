SRC = ft_printf.c print_int.c print_char.c print_str.c print_hexa.c print_unsigned.c print_addr.c

OBJ = ${SRC:.c=.o}

CFLAGS += -Wall -Werror -Wextra -I libftprintf.h

NAME = libftprintf.a

all: ${NAME}

${NAME}: ${OBJ}
		ar rc ${NAME} ${OBJ}
		ranlib ${NAME}

clean:
		rm -f ${OBJ}

fclean: clean
		rm -f ${NAME}

re:		fclean ${NAME}
