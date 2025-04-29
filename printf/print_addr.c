/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:25:14 by dagouill          #+#    #+#             */
/*   Updated: 2024/11/30 21:07:52 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	print_a(unsigned long long nb, int count, char *base)
{
	if (nb / 16)
		count += print_a(nb / 16, count, base);
	count += print_char(base[nb % 16]);
	return (count);
}

int	print_addr(unsigned long long n)
{
	char	*base;
	int		count;

	count = 0;
	if ((void *)n == NULL)
	{
		count += print_str(1, "(nil)");
		return (count);
	}
	base = "0123456789abcdef";
	print_str(1, "0x");
	count = print_a(n, count, base);
	count += 2;
	return (count);
}
