/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:08:31 by alevra            #+#    #+#             */
/*   Updated: 2022/11/30 19:49:22 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef BASE_HEXA
#  define BASE_HEXA "0123456789abcdef"
# endif

# ifndef BASE_HEXA_MAJ
#  define BASE_HEXA_MAJ "0123456789ABCDEF"
# endif

# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);

#endif