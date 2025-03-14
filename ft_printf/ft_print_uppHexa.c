/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uppHexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:38:24 by oessmiri          #+#    #+#             */
/*   Updated: 2024/11/07 08:19:44 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_upphexa(unsigned int n)
{
	int		r;
	char	*table;

	r = 0;
	table = "0123456789ABCDEF";
	if (n < 16)
		r += write(1, &table[n], 1);
	else
	{
		r += ft_print_upphexa(n / 16);
		r += write(1, &table[n % 16], 1);
	}
	return (r);
}
