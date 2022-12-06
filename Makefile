NAME = libftprintf.a

SRC =	ft_printf.c		\

HEADER = ft_printf.h

OBJ = $(SRC:.c=.o)

all	: libft/libft.a $(NAME)

$(NAME): libft/libft.a $(OBJ) 
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ)

libft/libft.a :
	make all -C libft

%.o : %.c  $(HEADER)
	gcc -c -Wall -Wextra -Werror $<

clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	rm -f libft/libft.a

re: fclean
	make all

.PHONY: all clean fclean re makelibft