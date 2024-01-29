NAME	=	philo

SRCS	=	./main.c \
			./arg_check.c \
			./utils.c \
			./init.c \
			./end.c \

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc

CFLAGS	=  -Wall -Wextra -Werror -pthread

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re