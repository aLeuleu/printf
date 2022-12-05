/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:08:31 by alevra            #+#    #+#             */
/*   Updated: 2022/12/05 22:16:03 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_ptr(unsigned long nbr)
{
	int	res;

	res = ft_putstr("0x");
	if (res < 0)
		return (-1);
	res = ft_put_u_nbr_base(nbr, BASE_HEXA);
	if (res < 0)
		return (-1);
	return (res + 2);
}

static int	switch_printf(char format, va_list args)
{
	if (format == 'c')
		return ((int)ft_putchar((char)va_arg(args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format == 'p')
		return (ft_put_ptr(va_arg(args, unsigned long)));
	if (format == 'd' || format == 'i')
		return (ft_itoa_printf(va_arg(args, int)));
	if (format == 'u')
		return (ft_put_u_nbr_base(va_arg(args, unsigned int), BASE_DEC));
	if (format == 'x')
		return (ft_put_u_nbr_base(va_arg(args, unsigned int), BASE_HEXA));
	if (format == 'X')
		return (ft_put_u_nbr_base(va_arg(args, unsigned int), BASE_HEXA_MAJ));
	if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		res;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		res = 0;
		if (str[i] == '%' && str[i + 1]
			&& ft_strchr("cspdiuxX%", (int)str[i + 1]))
			res = switch_printf(str[i++ + 1], args);
		else if (str[i] != '%')
			res = ft_putchar(str[i]);
		if (res < 0)
			return (-1);
		len += res;
		i++;
	}
	va_end(args);
	return (len);
}
