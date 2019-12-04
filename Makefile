##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

MAIN	=	main.c

SRC		=	src/push_swap.c			\
			src/print_list.c		\
			src/swap_list.c			\
			src/swap_actions.c		\
			src/push_list.c			\
			src/rotate_begin_list.c	\
			src/rotate_end_list.c	\
			src/verbose.c			\
			src/insertion_sort.c

CFLAGS	=	-I./include/ -Wall -Wextra

OBJ	=	$(MAIN:.c=.o) $(SRC:.c=.o)

NAME	=	push_swap

all:	$(NAME)

lib:
	make -s -C ./lib/my

$(NAME):	lib $(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib -lmy
	rm -f $(OBJ)

tests_run:	lib
	@find . -name "*.gc*" -delete
	gcc -o unit_tests $(SRC) tests/*.c -L./lib -lmy $(CFLAGS) --coverage -lcriterion
	./unit_tests
	mkdir -p coverage
	mv *.gc* coverage/

debug:	lib
	gcc -g -o $(NAME) $(MAIN) $(SRC) $(CFLAGS) -L./lib -lmy

clean:
	rm -f $(OBJ)
	rm -f unit_tests test*.gc*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all lib tests_run debug clean fclean re
