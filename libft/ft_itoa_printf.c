/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:53:28 by alevra            #+#    #+#             */
/*   Updated: 2022/11/25 08:39:03 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_abs(int n)
{
	unsigned int	res;

	if (n < 0)
		res = -n;
	else
		res = n;
	return (res);
}

static size_t	ft_nb_size(unsigned int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_itoa_printf(int n)
{
	int				i;
	int				size;
	char			*res;
	unsigned int	abs_n;

	abs_n = ft_abs(n);
	size = ft_nb_size(abs_n);
	if (n < 0)
		size ++;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (0);
	res[size] = '\0';
	i = 0;
	while (i < size)
	{
		res[size - i - 1] = abs_n % 10 + '0';
		abs_n /= 10;
		i++;
	}
	if (n < 0)
		res[0] = '-';
	ft_putstr(res);
	free(res);
	return (size);
}
