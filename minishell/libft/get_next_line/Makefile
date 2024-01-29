# Variables

NAME=gnl.a

FT_LIB_NAME=ft_lib.a

SRC_DIR=srcs/

OBJ_DIR=objs/

FT_LIB_DIR=../ft_lib/

FT_LIB=$(FT_LIB_DIR)$(FT_LIB_NAME)

HEAD=includes/

INCS = $(FT_LIB) includes/get_next_line.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rc
RANLIB = ranlib

SRC_FILES = get_next_line\
			get_next_line_utils\

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

$(FT_LIB):
	make -C $(FT_LIB_DIR) --no-print-directory

$(NAME):	$(OBJS) $(FT_LIB)
			@$(AR) $(NAME) $? $(FT_LIB_DIR)objs/*.o
			@$(RANLIB) $(NAME)
			@echo "\n\n\033[0;32mCompiled gnl!"
			@echo "\033[0m"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INCS) | $(OBJ_DIR)
				@printf "\033[0;33mGenerating gnl objects... %-33.33s\r" $@
				@$(CC) $(CFLAGS) -I$(HEAD) -c $< -o $@

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

clean:
	@make clean -C $(FT_LIB_DIR) --no-print-directory
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(FT_LIB_DIR) --no-print-directory

re: fclean all

.PHONY: all clean fclean re