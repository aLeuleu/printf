/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:53:02 by alevra            #+#    #+#             */
/*   Updated: 2022/11/28 14:28:20 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		base_is_valid(char *base);
static int				char_is_plus_or_minus(char c);

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned int		base_size;
	int					str_len;

	str_len = 0;
	if (!(base_is_valid(base)))
		return (0);
	base_size = ft_strlen(base);
	if (nbr > base_size -1)
	{
		str_len += ft_putnbr_base(nbr / base_size, base);
		str_len += ft_putnbr_base(nbr % base_size, base);
	}
	if (nbr < base_size)
	{
		ft_putchar(base[nbr]);
		str_len ++;
	}
	return (str_len);
}

static unsigned int	base_is_valid(char *base)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (base[i])
		if (char_is_plus_or_minus(base[i++]))
			return (0);
	if (i < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[i] == base [j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	char_is_plus_or_minus(char c)
{
	if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}
