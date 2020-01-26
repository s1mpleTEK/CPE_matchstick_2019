##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC	=	gcc

NAME	=	matchstick

TEST_CRITERION	=	unit_tests

BONUS	=	matchstick_bonus

MAIN	=	src/main.c

BONUS_MAIN	=	bonus/main_bonus.c

SRC	=	src/ai/ai_turn.c	\
		src/manage_map/full_map.c src/manage_map/print_map.c	\
		src/brain/game_loop.c	\
		src/check_interaction/check_input.c	\
		src/human/human_turn.c

OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o)

TEST_CRITERION_OBJ	=	$(SRC:.c=.o)

BONUS_OBJ	=	$(SRC:.c=.o) $(BONUS_MAIN:.c=.o)

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
	$(CC) $(OBJ) -o "$(NAME)" $(LIBDIR) $(LIB)

$(TEST_CRITERION):	$(TEST_CRITERION_OBJ) $(LIBMY)
	$(CC) -o $(TEST_CRITERION) $(TEST_FLAGS) $(LIBDIR) $(LIB)

$(BONUS):	$(LIBMY) $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) -o "$(BONUS)" $(LIBDIR) $(LIB)

tests_run:	$(TEST_CRITERION)
	./$(TEST_CRITERION)
	gcov *.gcna
	gcov *.gcno

bonus:	$(BONUS)

clean:
	rm -f $(OBJ)
	rm -f $(TEST_CRITERION_OBJ)
	rm -f $(BONUS_OBJ)
	$(MAKE) $(MAKE_LIB) clean
	rm -rf *.gcna
	rm -rf *.gcno
	rm -rf *.gcov

fclean:	clean
	rm -f $(NAME)
	rm -f $(TEST_CRITERION)
	rm -f $(BONUS)
	$(MAKE) $(MAKE_LIB) fclean

re:	fclean all

bonus_re:	fclean bonus

.PHONY:	all clean fclean re
