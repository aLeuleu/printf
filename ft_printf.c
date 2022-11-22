/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:08:31 by alevra            #+#    #+#             */
/*   Updated: 2022/11/22 19:43:57 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

#include "ft_putnbr_base.c"
#include "ft_put_u_nbr.c"
#include "ft_itoa_printf.c"
#include "ft_putchar.c"
#include "ft_putstr.c"

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
		ft_putstr("0x");
		return (ft_putnbr_base(va_arg(args, unsigned long), "0123456789abcdef") + 2);
	}
	else if (format == 'd' || format == 'i')
		return (ft_itoa_printf(va_arg(args, int)));
	else if (format == 'u')
		return (ft_put_u_nbr(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned long), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned long), "0123456789ABCDEF"));
	else if (format == '%')
		return (ft_putchar_printf('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	//penser à proteger son write ! .. 
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
		else if (!(str[i] == '%' && !str[i + 1] ))
			len += ft_putchar_printf(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
int main(int argc, char const *argv[])
{
	ft_printf("5yup+%X%p\f^%xGV%p<.ZAFV7.%uu<QU\tm3%c:lV9D%X@lY-kYl#", -1188388770, -1917131295, -385321198, -994562201, (void *)564382060602529785, -1443482557, (void 
*)7276484769049329218, -305677317, 1853607490, 874319342);
printf("\n");
	printf("5yup+%X%p\f^%xGV%p<.ZAFV7.%uu<QU\tm3%c:lV9D%X@lY-kYl#", -1188388770, -1917131295, -385321198, -994562201, (void *)564382060602529785, -1443482557, (void 
*)7276484769049329218, -305677317, 1853607490, 874319342);
printf("\n");
	return 0;
}
