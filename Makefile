NAME = libftprintf.a

SRC =	ft_printf.c		\
		ft_itoa_printf.c		\
		ft_putchar.c		\
		ft_putnbr.c		\
		ft_putstr.c		\
		ft_put_u_nbr.c		\
		ft_strlen.c		\
		ft_putnbr_base.c		\

HEADER = ft_printf.h

BONUS_SRC =

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all	: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o : %.c  ${HEADER} Makefile
	gcc -c -Wall -Wextra -Werror $<

clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: bonus all clean fclean re
