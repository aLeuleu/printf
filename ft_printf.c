/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:08:31 by alevra            #+#    #+#             */
/*   Updated: 2022/11/24 16:56:18 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_putchar_printf(char c)
{
	ft_putchar(c);
	return (1);
}

static int	switch_printf(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar_printf((char)va_arg(args, int)), 1);
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
	{
		return (ft_putstr("0x")
			+ ft_putnbr_base(va_arg(args, unsigned long), "0123456789abcdef"));
	}
	else if (format == 'd' || format == 'i')
		return (ft_itoa_printf(va_arg(args, int)));
	else if (format == 'u')
		return (ft_put_u_nbr(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned long),
				"0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned long),
				"0123456789ABCDEF"));
	else if (format == '%')
		return (ft_putchar_printf('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (write(1, 0, 0) < 0)
		return (0);
	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			len += switch_printf(str[i + 1], args);
			i++;
		}
		else if (!(str[i] == '%' && !str[i + 1]))
			len += ft_putchar_printf(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
