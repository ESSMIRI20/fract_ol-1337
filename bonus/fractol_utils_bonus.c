/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:23:25 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/14 14:12:24 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] == '\0')
			return (-1);
		if (str2[i] == '\0')
			return (1);
		if (str1[i] > str2[i])
			return (1);
		else if (str1[i] < str2[i])
			return (-1);
		i++;
	}
	return (0);
}

void	ml_put_pixel(t_value *data, int x, int y, int color)
{
	char	*val;

	val = data->addr + (y * data->len + x * (data->bits / 8));
	*(int *)val = color;
}

static void	it(double zr, double zi, t_value *val)
{
	double	t;

	while (zr * zr + zi * zi <= 4 && val->it < val->max_it)
	{
		t = val->cr + zr * zr - zi * zi;
		zi = val->ci + 2 * fabs(zr) * fabs(zi);
		zr = t;
		val->it++;
	}
}

void	burning_ship(t_value *val)
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
			val->ci = val->min_im + (j / (double)HEIGHT) * (val->max_im
					- val->min_im);
			zr = 0;
			zi = 0;
			val->it = 0;
			it(zr, zi, val);
			ml_put_pixel(val, i, j, get_color(val));
			j++;
		}
		i++;
	}
}
