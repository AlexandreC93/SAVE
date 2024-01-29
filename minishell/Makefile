# Variables

NAME		=minishell

LIBFT_DIR	= libft/

LIBFT_FILE	=libft.a

LIBFT		=$(LIBFT_DIR)$(LIBFT_FILE)

LIBFT_NAME	=ft

SRC_DIR		=srcs/

BUILTINS_DIR_NAME = builtins

EXEC_DIR_NAME = exec

PARSING_DIR_NAME = parsing

UTILS_DIR_NAME = utils

OBJ_DIR		=objs/

INC_DIR		=includes/

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC_FILES = main\
			inits\
			$(UTILS_DIR_NAME)/env\
			$(UTILS_DIR_NAME)/print\
			$(UTILS_DIR_NAME)/free\
			$(UTILS_DIR_NAME)/here_doc\
			$(UTILS_DIR_NAME)/status\
			$(UTILS_DIR_NAME)/utils\
			$(BUILTINS_DIR_NAME)/cd\
			$(BUILTINS_DIR_NAME)/echo\
			$(BUILTINS_DIR_NAME)/pwd\
			$(BUILTINS_DIR_NAME)/export\
			$(BUILTINS_DIR_NAME)/unset\
			$(BUILTINS_DIR_NAME)/ft_exit\
			$(BUILTINS_DIR_NAME)/builtins\
			$(EXEC_DIR_NAME)/execvp\
			$(EXEC_DIR_NAME)/exec\
			$(EXEC_DIR_NAME)/signals\
			$(EXEC_DIR_NAME)/piping\
			$(EXEC_DIR_NAME)/wait\
			$(PARSING_DIR_NAME)/ft_quotes\
			$(PARSING_DIR_NAME)/ft_split_argv\
			$(PARSING_DIR_NAME)/get_file\
			$(PARSING_DIR_NAME)/get_file_utils\
			$(PARSING_DIR_NAME)/ft_get_chevron_nb\
			$(PARSING_DIR_NAME)/ft_split_argv_utils\
			$(PARSING_DIR_NAME)/ft_expand\


SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)


$(LIBFT):
	@make all -C $(LIBFT_DIR) --no-print-directory

$(NAME):	$(OBJS) $(LIBFT)
			@$(CC) $(CFLAGS) -I$(INC_DIR) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -l$(LIBFT_NAME) -lreadline -lncurses
			@echo "\n\033[0;32mminishell is ready to use !\033[0m"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INC_DIR)*.h | $(OBJ_DIR)
				@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
				@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
			@-mkdir -p $(OBJ_DIR)
			@-mkdir -p $(OBJ_DIR)/$(BUILTINS_DIR_NAME)
			@-mkdir -p $(OBJ_DIR)/$(EXEC_DIR_NAME)
			@-mkdir -p $(OBJ_DIR)/$(PARSING_DIR_NAME)
			@-mkdir -p $(OBJ_DIR)/$(UTILS_DIR_NAME)

clean:
	@echo "\033[0;31mCleaning libft..."
	@make clean -C $(LIBFT_DIR) --no-print-directory
	@echo "\nRemoving binaries..."
	@$(RM) $(OBJ_DIR)
	@echo "\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR) --no-print-directory

re: fclean all
.PHONY: all clean fclean re

