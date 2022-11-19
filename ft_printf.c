/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:08:31 by alevra            #+#    #+#             */
/*   Updated: 2022/11/19 21:19:13 by alevra           ###   ########lyon.fr   */
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
	va_list	args;
	int		i;
	int		num_args;
	char	type;
	int		size;
	int		x;
	int		cumu_size;

	cumu_size = 0;
	size = get_next_str(str, '%', &type);
	va_start(args, str);
	while (*(str + size) && size)
	{
		if (!cumu_size)
			ft_putnstr(str, size);
		else
		{
			ft_putnstr(str, cumu_size);
		}
		cumu_size += size;
		if (type == 'd') 
		{
			x = va_arg(args, int);
			ft_putstr(ft_itoa(x));
		}
		size = get_next_str((str + cumu_size), '%', &type);
	}
	ft_putstr(str + cumu_size + 2);
	va_end(args);
}

int	main(int argc, char const *argv[])
{
	ft_printf("Bonjour, mon numero est le : %d et le chiffre complementaire c'est %d hihihi", 4, 10);
	return (0);
}
