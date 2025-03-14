/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:45:06 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/12 07:03:01 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	put_fractal(t_value val)
{
	burning_ship(&val);
	mlx_put_image_to_window(val.mlx_ptr, val.win_ptr, val.img, 0, 0);
}

void	check(int ac)
{
	if (ac != 2)
	{
		ft_printf("you must enter 2 arguments!\n");
		exit(1);
	}
}

void	helpe_function(t_value val)
{
	val.mlx_ptr = mlx_init();
	if (val.mlx_ptr == NULL)
		return ;
	val.win_ptr = mlx_new_window(val.mlx_ptr, WIDTH, HEIGHT, val.type);
	val.img = NULL;
	if (val.win_ptr == NULL)
	{
		ft_free(&val);
		return ;
	}
	val.img = mlx_new_image(val.mlx_ptr, WIDTH, HEIGHT);
	if (!val.img)
	{
		ft_free(&val);
		return ;
	}
	val.addr = mlx_get_data_addr(val.img, &val.bits, &val.len, &val.endian);
	put_fractal(val);
	mlx_hook(val.win_ptr, 2, 1L << 0, key_handler, &val);
	mlx_hook(val.win_ptr, 17, 1L << 17, ft_close, &val);
	mlx_mouse_hook(val.win_ptr, mouse_hook, &val);
	mlx_loop(val.mlx_ptr);
	ft_free(&val);
}

void	handle_type(t_value val)
{
	if (ft_strcmp("ship", val.type) == 0)
		helpe_function(val);
	else
	{
		ft_printf("you must enter like this arguments :\n- ship\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_value	val;

	check(ac);
	val.type = av[1];
	val.min_re = -2.0;
	val.max_re = 2.0;
	val.min_im = -2.0;
	val.max_im = 2.0;
	val.max_it = 42;
	val.color = 1;
	handle_type(val);
	return (0);
}
