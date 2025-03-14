/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:39:53 by oessmiri          #+#    #+#             */
/*   Updated: 2024/11/26 10:52:40 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	form(va_list arg, const char f)
{
	int	i;

	i = 0;
	if (f == 'c')
		i += ft_putchar(va_arg(arg, int));
	else if (f == 's')
		i += ft_putstr(va_arg(arg, char *));
	else if (f == 'd')
		i += ft_putnbr(va_arg(arg, int));
	else if (f == 'i')
		i += ft_putnbr(va_arg(arg, int));
	else if (f == 'x')
		i += ft_print_lowhexa(va_arg(arg, unsigned int));
	else if (f == 'X')
		i += ft_print_upphexa(va_arg(arg, unsigned int));
	else if (f == 'p')
		i += ft_print_addr(va_arg(arg, unsigned long));
	else if (f == 'u')
		i += ft_print_unsd(va_arg(arg, unsigned int));
	else if (f == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		j;
	va_list	arg;

	i = 0;
	j = 0;
	if (!s)
		return (-1);
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			j += form(arg, s[i + 1]);
			i += 2;
		}
		else
		{
			j += ft_putchar(s[i]);
			i++;
		}
	}
	va_end(arg);
	return (j);
}
