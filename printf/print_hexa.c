/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:53:54 by dagouill          #+#    #+#             */
/*   Updated: 2024/11/30 20:27:24 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	int	print_h(long nb, int count, char *base)
{
	if (nb < 0)
	{
		count += print_char('-');
		nb = -nb;
	}
	if (nb / 16)
		count += print_h(nb / 16, count, base);
	count += print_char(base[nb % 16]);
	return (count);
}

int	print_hexa(unsigned int n, char *base)
{
	int	count;

	count = 0;
	count += print_h((long)n, count, base);
	return (count);
}
