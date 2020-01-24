##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC	=	gcc

NAME	=	matchstick

TEST	=	unit_tests

MAIN	=	src/main.c

SRC	=	src/ai/ai_turn.c	\
		src/manage_map/full_map.c src/manage_map/print_map.c	\
		src/brain/game_loop.c	\
		src/check_interaction/check_input.c	\
		src/human/human_turn.c

OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o)

TEST_OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra

TEST_FLAGS	=	-lcriterion -lgcov --coverage

MAKE_LIB = -C ./lib/my/

LIB = -lmy

LIBDIR = -L./lib/

LIBMY = ./lib/libmy.a

INCLUDE	=	-I./include/

all:	$(NAME)

%.o:	%.c
	$(CC) -o $@ -c $< $(INCLUDE) $(CFLAGS)

$(LIBMY):
	$(MAKE) $(MAKE_LIB)

$(NAME):	$(LIBMY) $(OBJ)
	$(CC) -g3 $(OBJ) -o "$(NAME)" $(LIBDIR) $(LIB)

$(TEST):	$(TEST_OBJ) $(LIBMY)
	$(CC) -o $(TEST) $(TEST_FLAGS) $(LIBDIR) $(LIB)

tests_run:	$(TEST)
	./$(TEST)
	gcov *.gcna
	gcov *.gcno

clean:
	rm -f $(OBJ)
	rm -f $(TEST_OBJ)
	$(MAKE) $(MAKE_LIB) clean
	rm -rf *.gcna
	rm -rf *.gcno
	rm -rf *.gcov

fclean:	clean
	rm -f $(NAME)
	rm -f $(TEST)
	$(MAKE) $(MAKE_LIB) fclean

re:	fclean all

.PHONY:	all clean fclean re
