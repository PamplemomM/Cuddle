##
## EPITECH PROJECT, 2024
## Task01 Makefile
## File description:
## First makefile
##

NAME	=	libcuddle.a

SRCS	=	$(shell find src/ -type f -name '*.c')

SRCTEST	=	$(shell find src/lib -type f -name '*.c')
SRCTEST	+=	$(shell find src/is_functions -type f -name '*.c')
SRCTEST	+=	$(shell find tests/ -type f -name '*.c')

OBJS	=	$(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Wshadow

$(NAME)	:	$(OBJS)
			ar rc $(NAME) $(OBJS)

all		:	$(NAME)

run		:
			gcc -o cuddle -g3 $(SRCS) do_not_push.c

clean	:
		rm -f $(OBJS)

fclean	:	clean
			rm -f cuddle
			rm -f $(NAME)

tests_run:
	gcc -o unit_tests $(SRCTEST) -Iinclude -lcriterion --coverage
	./unit_tests

re		:	fclean all
