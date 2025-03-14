/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:17:45 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/12 07:02:55 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "mlx.h"
# include "ft_printf/ft_printf.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 700
# define HEIGHT 600

typedef struct s_avlue{
	void	*win_ptr;
	void	*mlx_ptr;
	void	*img;
	char	*addr;
	int		len;
	int		bits;
	int		it;
	int		endian;
	double	zoom;
	double	min_re;
	double	min_im;
	double	max_re;
	double	max_im;
	double	cr;
	double	ci;
	char	*type;
	int		max_it;
	int		color;
}t_value;

typedef struct s_atof
{
	double	result;
	double	fraction;
	int		sign;
}t_atof;

void	ml_put_pixel(t_value *data, int x, int y, int color);
void	julia(t_value *val);
double	ft_atof(const char *str);
int		get_color(t_value *val);
void	check(int ac);
void	handle_type(t_value val);
int		mouse_hook(int button, int x, int y, t_value *data);
void	put_fractal(t_value val);
int		key_handler(int keycode, t_value *data);
void	ft_free(t_value *val);
int		ft_close(t_value *va);
void	count_it(double zr, double zi, t_value *val);
void	burning_ship(t_value *val);
int		ft_strcmp(char *s1, char *s2);

#endif
