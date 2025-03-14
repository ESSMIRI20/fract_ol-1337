NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

files = ft_print_addr.c ft_print_uppHexa.c ft_putnbr.c ft_print_lowHexa.c \
	ft_putchar.c ft_putstr.c ft_printf.c ft_print_unsd.c

OBJCT = $(files:.c=.o)

all : $(NAME)

$(NAME) : ${OBJCT}
	ar -rcs $(NAME) ${OBJCT}

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f ${OBJCT}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
