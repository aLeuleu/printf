/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:08:31 by alevra            #+#    #+#             */
/*   Updated: 2022/11/19 16:18:10 by alevra           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include <stdarg.h>

int max(int num_args, ...)
{
    va_list args;
    int i;
    va_start(args, num_args);

    for (i = 0; i < num_args; i++)
    {
        int x = va_arg(args, int);
        printf("x : %d\n", x);
    }

    va_end(args);
}

int main(int argc, char const *argv[])
{
    max(3, 5,50, 5000);
    return 0;
}
