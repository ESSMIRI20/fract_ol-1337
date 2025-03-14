/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:23:25 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/11 15:57:40 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	type_cmp(char *type)
{
	int		i;

	i = 0;
	while (type[i])
	{
		if (type[i] <= 'Z' && type[i] >= 'A')
			type[i] += 32;
		i++;
	}
	if (ft_strcmp(type, "mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(type, "julia") == 0)
		return (2);
	return (0);
}

void	ml_put_pixel(t_value *data, int x, int y, int color)
{
	char	*val;

	val = data->addr + (y * data->len + x * (data->bits / 8));
	*(int *)val = color;
}

double	helper_atof(const char *str, double result, double fraction)
{
	if (*str == '.')
	{
		str++;
		while (*str)
		{
			if (*str < '0' || *str > '9')
				return (42);
			else
			{
				result += (*str - '0') * fraction;
				fraction /= 10;
			}
			str++;
		}
	}
	return (result);
}

double	ft_atof(const char *str)
{
	t_atof	atof;

	atof.result = 0.0;
	atof.fraction = 0.1;
	atof.sign = 1;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			atof.sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str == '.')
			break ;
		else if (*str >= '0' && *str <= '9')
			atof.result = atof.result * 10 + (*str - '0');
		else if (*str < '0' || *str > '9')
			return (42);
		str++;
	}
	return (helper_atof(str, atof.result, atof.fraction) * atof.sign);
}
