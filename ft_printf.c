/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:08:31 by alevra            #+#    #+#             */
/*   Updated: 2022/11/20 13:42:29 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	ft_putstr_fd(str, 1);
}

void	ft_putnstr(char *s, size_t len)
{
	while (len-- > 0 && *s)
	{
		write(1, s++, 1);
	}
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

char	*ft_strnew(size_t size)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	while (size > 0)
		res[size--] = 0;
	return (res);
}

#include <string.h>
int	get_next_str(char *str_src, char c, char *type)
{
	int			count;
	static int	already_read;
	char		*str;
	int			size;

	count = 0;
	//char *s = ft_strchr(str,c)
	str = ft_strchr(str_src, c);
	if (!str || !*str)
	{
		return (already_read + 1);
	}
	str += already_read;
	size = str - str_src;
	already_read = size;
	*type = str_src[size + 1];
	return (size);
}

void	ft_printf(char *str, ...)
{
	va_list args;
	int i;
	va_start(args,str);
	i= 0;
	while ( str && str[i])
	{
		while (str[i] && str[i] != '%' && str[i] != '/' )
			ft_putchar_fd(str[i++],1);
		if (str[i] == '%')
		{
			i++;
			int x = va_arg(args,int);
			if (str[i] == 'd')
				ft_putstr(ft_itoa(x));
			i++;
		}
	}
	va_end(args);
}
int	main(int argc, char const *argv[])
{
	ft_printf("Bonjour, mon numero est le : %d et le chiffre complementaire c'est %d hihihi", 4, 10);
	return (0);
}
