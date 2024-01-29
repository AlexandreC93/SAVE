NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rc

ARX = ar x

RM = rm -f

RANLIB = ranlib

FT_LIB_DIR = ft_lib/

FT_LIB = $(FT_LIB_DIR)ft_lib.a

PRINTF_DIR = ft_printf/

PRINTF = $(PRINTF_DIR)ft_printf.a

GNL_DIR = get_next_line/

GNL = $(GNL_DIR)gnl.a

all: $(NAME)

$(FT_LIB):
	@echo "\n\n\033[0;34mCompiling ft_lib..."
	@make -C $(FT_LIB_DIR) --no-print-directory

$(PRINTF):
	@echo "\033[0;34mCompiling ft_printf..."
	@make -C $(PRINTF_DIR) --no-print-directory

$(GNL):
	@echo "\033[0;34mCompiling get_next_line..."
	@make -C $(GNL_DIR) --no-print-directory

$(NAME): $(FT_LIB) $(PRINTF) $(GNL)
	@echo "\033[0;34mCompiling libft..."
	@$(ARX) $(FT_LIB)
	@$(ARX) $(PRINTF)
	@$(ARX) $(GNL)
	@$(AR) $(NAME) *.o
	@$(RANLIB) $(NAME)
	@$(RM) *.o
	@echo "\n\033[0;32mCompiled libft!\033[0m"

clean:
	@make clean -C $(FT_LIB_DIR) --no-print-directory
	@make clean -C $(PRINTF_DIR) --no-print-directory
	@make clean -C $(GNL_DIR) --no-print-directory

fclean: clean
	@echo "\033[0;31mCleaning ft_lib..."
	@make fclean -C $(FT_LIB_DIR) --no-print-directory
	@echo "\033[0;31mCleaning ft_printf..."
	@make fclean -C $(PRINTF_DIR) --no-print-directory
	@echo "\033[0;31mCleaning get_next_line..."
	@make fclean -C $(GNL_DIR) --no-print-directory
	@$(RM) $(NAME)
	@echo "Done !"
	@echo "\033[0m"

re: fclean all

.PHONY: all clean fclean re