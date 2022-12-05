#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("printf :\n");
	int a = printf("%p\n", "");
	printf("a : %d \n", a);
	printf("ft_printf :\n");
	a = ft_printf("%p\n", "");
	printf("a : %d \n", a);
	return (0);
}
