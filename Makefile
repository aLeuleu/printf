NAME = libftprintf.a

SRC =	ft_printf.c		\

HEADER = ft_printf.h

BONUS_SRC =

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all	: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

#bonus: $(BONUS_OBJ)
#	ar -rcs $(NAME) $(BONUS_OBJ)

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
