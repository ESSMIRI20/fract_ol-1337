/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:34:54 by oessmiri          #+#    #+#             */
/*   Updated: 2024/11/24 20:08:57 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	ft_print_low(unsigned long n)
{
	char	*table;
	int		r;

	r = 0;
	table = "0123456789abcdef";
	if (n < 16)
		r += write(1, &table[n], 1);
	else
	{
		r += ft_print_low(n / 16);
		r += write(1, &table[n % 16], 1);
	}
	return (r);
}

int	ft_print_addr(unsigned long n)
{
	if (n == 0)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (ft_print_low(n) + 2);
}
