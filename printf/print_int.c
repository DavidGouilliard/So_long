/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:40:50 by dagouill          #+#    #+#             */
/*   Updated: 2024/11/27 18:17:08 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_i(long nb, int count)
{
	if (nb < 0)
	{
		print_char('-');
		return (print_i(-nb, count) + 1);
	}
	if (nb / 10)
		count += print_i(nb / 10, count);
	count += print_char(nb % 10 + '0');
	return (count);
}

int	print_int(int n)
{
	int	count;

	count = 0;
	count = print_i((long) n, count);
	return (count);
}
