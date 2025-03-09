##
## EPITECH PROJECT, 2024
## Task01 Makefile
## File description:
## First makefile
##

NAME	=	libcuddle.a

SRCS	=	src/*.c

OBJS	=	$(SRCS:.c=.o)

$(NAME)	:	$(OBJS)
			ar rc $(NAME) $(OBJS)

all		:	$(NAME)

clean	:
		rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all
