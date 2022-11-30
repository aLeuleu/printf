#include "ft_printf.h"
#include "ft_printf.c"
#include <stdio.h>
#include "libft/ft_itoa_printf.c"
#include "libft/ft_put_u_nbr.c"
#include "libft/ft_putchar.c"
#include "libft/ft_putnbr_base.c"
#include "libft/ft_putstr.c"
#include "libft/ft_strlen.c"
#include "libft/ft_strchr.c"
#include "libft/ft_putnbr.c"

int main(int argc, char const *argv[])
{

	printf("ft_printf :\n");
	int a = ft_printf("%d", -12);
	printf("\na : %d \n", a);
	printf("printf :\n");
	a = printf("%d", -12);
	printf("\na : %d \n", a);
	return 0;
}
