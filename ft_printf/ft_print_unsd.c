/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:09:04 by oessmiri          #+#    #+#             */
/*   Updated: 2024/11/05 16:43:23 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_unsd(unsigned int n)
{
	char	buffer[11];
	int		i;
	int		j;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	j = i;
	while (i > 0)
		write(1, &buffer[--i], 1);
	return (j);
}
