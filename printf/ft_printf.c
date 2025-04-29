/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:25:30 by dagouill          #+#    #+#             */
/*   Updated: 2024/11/30 21:06:45 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	parse_flags(const char i, va_list ap)
{
	if (i == 'c')
		return (print_char(va_arg(ap, int)));
	else if (i == 'i' || i == 'd')
		return (print_int(va_arg(ap, int)));
	else if (i == 'u')
		return (print_unsigned(va_arg(ap, unsigned int)));
	else if (i == '%')
		return (print_char('%'));
	else if (i == 's')
		return (print_str(1, va_arg(ap, char *)));
	else if (i == 'x')
		return (print_hexa(va_arg(ap, int), "0123456789abcdef"));
	else if (i == 'X')
		return (print_hexa(va_arg(ap, int), "0123456789ABCDEF"));
	else if (i == 'p')
		return (print_addr(va_arg(ap, unsigned long long)));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, str);
	if (!str)
		return (-1);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += parse_flags(*str, ap);
		}
		else
			count += print_char(*str);
		str++;
	}
	va_end(ap);
	return (count);
}
