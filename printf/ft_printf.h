/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagouill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:02:33 by dagouill          #+#    #+#             */
/*   Updated: 2024/11/30 21:06:58 by dagouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

int	ft_printf(const char *str, ...);
int	print_char(int i);
int	print_str(int fd, char *str);
int	print_hexa(unsigned int nb, char *base);
int	print_unsigned(unsigned int n);
int	print_int(int n);
int	print_addr(unsigned long long n);

#endif
