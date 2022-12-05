#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{

	printf("ft_printf :\n");
	int a = ft_printf("%x", LONG_MAX);
	printf("\na : %d \n", a);
	printf("printf :\n");
	a = printf("%lx", LONG_MAX);
	printf("\na : %d \n", a);
	return 0;
}
