/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:47:43 by dagouill          #+#    #+#             */
/*   Updated: 2024/11/27 18:17:14 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_u(unsigned long nb, int count)
{
	if (nb / 10)
		count += print_u(nb / 10, count);
	count += print_char(nb % 10 + '0');
	return (count);
}

int	print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	count = print_u((unsigned long) n, count);
	return (count);
}
