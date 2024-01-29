NAME	= Sed
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

all: $(NAME)

$(NAME): 
	@printf "Compiling $(NAME)\n"
	@ $(CC) $(FLAGS) main.cpp Utils.cpp -o $(NAME)
	@printf "Exec ready\n"

clean:
	@$(RM) $(NAME)
	@printf "Exec removed\n"

fclean:
	@$(RM) $(NAME)
	@printf "Exec removed\n"

re: clean all

.PHONY: all clean re
