##
## EPITECH PROJECT, 2019
## Makefile lib
## File description:
## Makefile
##

CC = gcc

INCLUDE = -I../../include/

SRC = my_swap.c my_getnbr.c base_flag_bin.c base_flag_dec_and_long_dec.c base_flag_hex.c base_flag_long_hex.c \
	base_flag_oct_and_long_oct.c base_flag_pointer.c base_flag_upper_s.c basic_flag.c my_printf.c my_put_nbr.c \
	my_putchar.c my_putstr.c my_strlen.c mem.c my_str_isnum.c

OBJ = $(SRC:.c=.o)

NAME = ../libmy.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(INCLUDE)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re