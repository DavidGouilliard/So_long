/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:51:34 by dagouill          #+#    #+#             */
/*   Updated: 2024/11/30 21:13:18 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	print_s(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write (fd, str, i);
	return (i);
}

int	print_str(int fd, char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		count = print_s(1, "(null)");
		return (count);
	}
	count = print_s(fd, str);
	return (count);
}
