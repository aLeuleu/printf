NAME = libftprintf.a

SRC =	ft_printf.c		\

HEADER = ft_printf.h

BONUS_SRC =

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all	: makelibft $(NAME)

$(NAME): $(OBJ) 
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ)
	
makelibft :
	make -C libft

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

.PHONY: bonus all clean fclean re makelibft