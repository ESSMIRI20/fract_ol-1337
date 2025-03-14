/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_third_Utls_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:12:45 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/11 16:04:03 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
