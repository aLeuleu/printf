/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:08:31 by alevra            #+#    #+#             */
/*   Updated: 2022/11/30 22:04:43 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	switch_printf(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar((char)va_arg(args, int)), 1);
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format == 'p')
	{
		return (ft_putstr("0x")
			+ ft_putnbr_base(va_arg(args, unsigned long), BASE_HEXA));
	}
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int))); //ne pas faire de malloc .. ou alors gerer les cas ou le malloc pete
	if (format == 'u')
		return (ft_put_u_nbr(va_arg(args, unsigned int)));
	if (format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned long),
				BASE_HEXA));
	if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned long), BASE_HEXA_MAJ));
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

	if (write(1, 0, 0) < 0)
		return (-1);
	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1]
			&& ft_strchr("cspdiuxX%", (int)str[i + 1]))
		{
			len += switch_printf(str[i + 1], args);
			i++;
		}
		else if (str[i] != '%')
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	return (va_end(args), len);
}
