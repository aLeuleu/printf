/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:08:31 by alevra            #+#    #+#             */
/*   Updated: 2022/11/21 20:36:18 by alevra           ###   ########lyon.fr   */
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

int	switch_printf(char *format, va_list args)
{
	int x;

	if (format[0] == 'd')
	{
		va_arg(args, int);
		ft_putstr(ft_itoa);
	}
}

void	ft_printf(char *str, ...)
{
	va_list			args;
	int				i;
	unsigned int	len;
	//penser à proteger son write ! .. 
	va_start(args, str);
	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == '%')
			switch_printf(str + i + 1, args);
		else
			ft_putchar_printf();
		i++;
	va_end(args);
}

#include "libft.h"

int	main(int argc, char const *argv[])
{
	ft_printf("Numero : %d et puis %d hihihi", 4, 10);
	ft_printf("");
	//ft_printf("%");
	//ft_printf(NULL);
	//ft_printf("%d", 0);
	//ft_printf(0);
	return (0);
}
