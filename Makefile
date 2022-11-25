NAME = libftprintf.a

SRC =	ft_printf.c		\

HEADER = ft_printf.h

BONUS_SRC =

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all	: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ)

%.o : %.c  ${HEADER} Makefile
	gcc -c -Wall -Wextra -Werror $<

clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean
	make all

libft.a : 

.PHONY: bonus all clean fclean re
