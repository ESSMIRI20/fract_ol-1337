CC = cc
CFLAGS = -I /usr/include/minilibx-linux -I . -Wall -Wextra -Werror

PATH1 = /usr/include/minilibx-linux/libmlx.a -lXext -lX11
PATH2 = ft_printf/libftprintf.a
NAME = fractol
BONUS_NAME = fractol_bonus

F = fractol.c fractol_utils.c fractol_second_Utls.c fractol_third_Utls.c

bonus_F = bonus/fractol_bonus.c bonus/fractol_utils_bonus.c bonus/fractol_second_Utls_bonus.c bonus/fractol_third_Utls_bonus.c

OB = $(F:.c=.o)
BONUS_OB = $(bonus_F:.c=.o)

all: $(PATH2) $(NAME)
bonus : $(PATH2) $(BONUS_NAME)

$(PATH2):
	$(MAKE) -C ft_printf

$(NAME): $(OB)
	$(CC) $(CFLAGS) $(OB) -o $(NAME) $(PATH2) $(PATH1)

$(BONUS_NAME): $(BONUS_OB)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OB) $(PATH2) $(PATH1)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -vf $(OB) $(BONUS_OB)
	$(MAKE) clean -C ft_printf

fclean: clean
	rm -vf $(NAME) $(BONUS_NAME)
	$(MAKE) fclean -C ft_printf

re: fclean all

.PHONY: clean
