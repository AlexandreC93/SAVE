NAME	= Battle
	
CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

all: $(NAME)

$(NAME): 
	@printf "Compiling $(NAME)\n"
	@ $(CC) $(FLAGS) main.cpp HumanB.cpp HumanA.cpp Weapon.cpp -o $(NAME)
	@printf "Exec ready\n"

clean:
	@$(RM) $(NAME)
	@printf "Exec removed\n"

fclean:
	@$(RM) $(NAME)
	@printf "Exec removed\n"

re: clean all

.PHONY: all clean re