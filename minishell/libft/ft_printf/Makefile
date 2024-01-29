# Variables

NAME=ft_printf.a

FT_LIB_NAME=ft_lib.a

SRC_DIR=srcs/

OBJ_DIR=objs/

FT_LIB_DIR=../ft_lib/

FT_LIB=$(FT_LIB_DIR)$(FT_LIB_NAME)

HEAD=includes/

INCS = $(FT_LIB) includes/ft_printf.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rc
RANLIB = ranlib

SRC_FILES = ft_printf\
		  ft_printf_print_c\
		  ft_printf_print_s\
		  ft_printf_print_p\
		  ft_printf_print_di\
		  ft_printf_print_u\
		  ft_printf_print_x\
		  ft_printf_print_utils\
		  ft_printf_parse\

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

$(FT_LIB):
	@make -C $(FT_LIB_DIR) --no-print-directory

$(NAME):	$(OBJS) $(FT_LIB)
			@$(AR) $(NAME) $? $(FT_LIB_DIR)objs/*.o
			@$(RANLIB) $(NAME)
			@echo "\n\n\033[0;32mCompiled ft_printf!"
			@echo "\033[0m"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INCS) | $(OBJ_DIR)
				@printf "\033[0;33mGenerating ft_printf objects... %-33.33s\r" $@
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