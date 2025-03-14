/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_second_Utls_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:47:04 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/14 14:13:47 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	get_color(t_value *val)
{
	if (val->it == val->max_it)
		return (0);
	return ((val->it * 255 / val->max_it) << (val->color + 8) | (val->it * 255
			/ val->max_it) << val->color | (val->it * 255 / val->max_it));
}

int	mouse_hook(int button, int x, int y, t_value *data)
{
	double	mouse_re;
	double	mouse_im;

	if (button == 4)
		data->zoom = 0.9;
	else if (button == 5)
		data->zoom = 1.1;
	if (button == 4 || button == 5)
	{
		mouse_re = data->min_re + (double)x / WIDTH * (data->max_re
				- data->min_re);
		mouse_im = data->min_im + (double)y / HEIGHT * (data->max_im
				- data->min_im);
		data->min_re = mouse_re + (data->min_re - mouse_re) * data->zoom;
		data->max_re = mouse_re + (data->max_re - mouse_re) * data->zoom;
		data->min_im = mouse_im + (data->min_im - mouse_im) * data->zoom;
		data->max_im = mouse_im + (data->max_im - mouse_im) * data->zoom;
		put_fractal(*data);
	}
	return (0);
}

void	handler(int key, t_value *val)
{
	double	move;

	move = (val->max_re - val->min_re) * 0.1;
	if (key == XK_Right)
	{
		val->min_re -= move;
		val->max_re -= move;
	}
	else if (key == XK_Left)
	{
		val->min_re += move;
		val->max_re += move;
	}
	else if (key == XK_Up)
	{
		val->min_im += move;
		val->max_im += move;
	}
	else if (key == XK_Down)
	{
		val->min_im -= move;
		val->max_im -= move;
	}
}

int	key_handler(int keycode, t_value *data)
{
	handler(keycode, data);
	if (keycode == 65451)
		data->max_it += 1;
	else if (keycode == 65453)
		data->max_it -= 1;
	else if (keycode == 32)
		data->color += 1;
	else if (keycode == XK_Escape)
	{
		ft_free(data);
		exit(1);
	}
	put_fractal(*data);
	return (0);
}
