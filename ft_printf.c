/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:08:31 by alevra            #+#    #+#             */
/*   Updated: 2022/11/19 20:52:21 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

void	ft_putstr(char *str)
{
	ft_putstr_fd(str, 1);
}

char	*ft_strncpy(char *dest,const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] =src[i];
		i++;
	}
	while ( i < n )
		dest[i++] = '\0';
	return (dest);
}

char	*ft_strnew(size_t size)
{
	char	*res;

	res = (char *)malloc( sizeof(char) * size);
	if (!res)
		return (NULL);
	while (size > 0)
		res[size--] = 0;
	return (res);
}

#include <string.h>
char	*get_next_str(char *str_src, char c, char *type)
{
	int count;
	static int already_read = 0;
	count = 0;
	//char *s = ft_strchr(str,c)
	char *str = ft_strchr(str_src,c);
	if (!str || !*str)
		return (NULL);
	str += already_read;
	int size = str - str_src;
	already_read = size;
	*type = str_src[size + 1];
	char *new_str = ft_strnew(size);
	new_str = ft_strncpy(new_str, (const char *) str_src, size);

/* 	if (type == 'd')
 */
	return (new_str);
}

void ft_printf(char *str, ...)
{
	va_list args;
	int i;
	int num_args;
	char type;
	char *next_str = get_next_str(str,'%', &type);
	
	va_start(args, str);
	while (next_str && next_str[0])
	{
		ft_putstr(next_str);
		if (type == 'd')
		{
			int x = va_arg(args, int);
			ft_putstr(ft_itoa(x));
		}
		next_str = get_next_str(next_str,'%', &type);
	}
	va_end(args);
}

int main(int argc, char const *argv[])
{ 
	ft_printf("Bonjour, mon numero est le : %dhihihi", 4);
	return 0;
}
