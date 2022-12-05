/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:08:31 by alevra            #+#    #+#             */
/*   Updated: 2022/12/05 13:39:14 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	switch_printf(char format, va_list args)
{
	if (format == 'c')
		return ((int)ft_putchar((char)va_arg(args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format == 'p')
	{
		return (ft_putstr("0x")
			+ ft_put_u_nbr_base(va_arg(args, unsigned long), BASE_HEXA));
	}
	if (format == 'd' || format == 'i')
		return (ft_itoa_printf(va_arg(args, int)));
	if (format == 'u')
		return (ft_put_u_nbr(va_arg(args, unsigned int)));
	if (format == 'x')
		return (ft_putnbr_base(va_arg(args, long long),
				BASE_HEXA));
	if (format == 'X')
		return (ft_putnbr_base(va_arg(args, long long), BASE_HEXA_MAJ));
	if (format == '%')
		return (ft_putchar('%'), 1);
	return (0);
}

//faire passer paco strict

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		res;

	if (write(1, 0, 0) < 0)
		return (-1);
	va_start(args, str);
	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1]
			&& ft_strchr("cspdiuxX%", (int)str[i + 1]))
			res = switch_printf(str[i++ + 1], args);
		else if (str[i] != '%')
			res = ft_putchar(str[i]);
		if (res < 0)
			return (-1);
		len += res;
	}
	return (va_end(args), len);
}
