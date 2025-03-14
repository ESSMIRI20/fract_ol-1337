/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lowHexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:11:08 by oessmiri          #+#    #+#             */
/*   Updated: 2024/11/07 19:09:36 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_lowhexa(unsigned int n)
{
	char	*table;
	int		r;

	r = 0;
	table = "0123456789abcdef";
	if (n < 16)
		r += write(1, &table[n], 1);
	else
	{
		r += ft_print_lowhexa(n / 16);
		r += write(1, &table[n % 16], 1);
	}
	return (r);
}
