/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_third_Utls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:12:45 by oessmiri          #+#    #+#             */
/*   Updated: 2025/02/21 22:12:49 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	count_it(double zr, double zi, t_value *val)
{
	double	t;

	while (zr * zr + zi * zi <= 4 && val->it < val->max_it)
	{
		t = val->cr + zr * zr - zi * zi;
		zi = val->ci + 2 * zr * zi;
		zr = t;
		val->it++;
	}
}

void	ft_free(t_value *val)
{
	if (val->img)
		mlx_destroy_image(val->mlx_ptr, val->img);
	if (val->win_ptr)
		mlx_destroy_window(val->mlx_ptr, val->win_ptr);
	if (val->mlx_ptr)
	{
		mlx_destroy_display(val->mlx_ptr);
		free(val->mlx_ptr);
	}
}

int	ft_close(t_value *va)
{
	ft_free(va);
	exit(1);
}

void	mandlbrot(t_value *val)
{
	int		i;
	int		j;
	double	zr;
	double	zi;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			val->cr = val->min_re + (i / (double)WIDTH) * (val->max_re
					- val->min_re);
			val->ci = val->max_im - (j / (double)HEIGHT) * (val->max_im
					- val->min_im);
			zr = 0;
			zi = 0;
			val->it = 0;
			count_it(zr, zi, val);
			ml_put_pixel(val, i, j, get_color(val));
			j++;
		}
		i++;
	}
}

void	julia(t_value *val)
{
	int		i;
	int		j;
	double	zr;
	double	zi;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			zr = val->min_re + (i / (double)WIDTH) * (val->max_re
					- val->min_re);
			zi = val->max_im - (j / (double)HEIGHT) * (val->max_im
					- val->min_im);
			val->it = 0;
			count_it(zr, zi, val);
			ml_put_pixel(val, i, j, get_color(val));
			j++;
		}
		i++;
	}
}
