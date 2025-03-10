##
## EPITECH PROJECT, 2024
## Task01 Makefile
## File description:
## First makefile
##

NAME	=	libcuddle.a

SRCS	=	$(shell find src/ -type f -name '*.c')

SRCTEST	=	tests/*.c src/lib/*.c

OBJS	=	$(SRCS:.c=.o)

$(NAME)	:	$(OBJS)
			ar rc $(NAME) $(OBJS)

all		:	$(NAME)

clean	:
		rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

tests_run:
	gcc -o unit_tests $(SRCTEST) -Iinclude -lcriterion --coverage
	./unit_tests

re		:	fclean all
