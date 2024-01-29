NAME = push_swap

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRC =	./src/utils/chain_list.c  \
		./src/utils/chain_list_insertion.c  \
		main.c \
		./src/parsing/parsing.c \
		./src/parsing/parsing_utils.c \
		./src/sorting/sort_big_stack.c \
		./src/sorting/sort_small_stack.c \
		./src/utils/utils.c \
		./src/utils/utils_sorting.c \
		./src/utils/ops.c \
		./src/sorting/sort_list_of_three.c \
		./src/sorting/sort_list_of_four.c \
		./src/sorting/sort_list_of_five.c \


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) include/push_swap.h
			make -C libft
			clang -o $(NAME) $(OBJ) $(CFLAGS) -I libft libft/libft.a

clean :
			rm -rf $(OBJ)
			make clean -C libft

fclean : clean
			rm -rf $(NAME)
			make fclean -C libft

re : fclean all

.PHONY : all clean fclean re
