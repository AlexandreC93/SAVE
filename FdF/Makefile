NAME        = FdF
LIBFT       = ./libft/
MLX         = mlx_linux/minilibx-linux/
LIBFT_A     = $(addprefix $(LIBFT), libft.a)
MLX_A       = $(addprefix $(MLX), libmlx.a)
MLXF		=  -Lmlx_linux -lmlx_Linux

CC          = gcc -Wall -Wextra -Werror
RM          = rm -f
SRCS        = fdf.c \
              ./srcs/map.c \
              ./srcs/utils.c \
              ./srcs/hooks.c \
              ./srcs/mouse.c \
              ./srcs/draw.c \
              ./srcs/alg.c \
              ./srcs/line.c \
              ./srcs/project.c \
              ./srcs/keyboard.c \
			  ./srcs/tools.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_A) fdf.h
	@$(CC) $(OBJS) $(MLXF) -L$(LIBFT) -lft -L$(MLX) -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "Linked into executable \033[0;32m$(NAME)\033[0m."

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT_A):
	@$(MAKE) -s -C $(LIBFT)
	@echo "Compiled $(LIBFT_A)."

$(MLX_A):
	@$(MAKE) -s -C $(MLX)
	@echo "Compiled $(MLX_A)."

localclean:
	@$(RM) $(OBJS)
	@echo "Removed object files."

clean: localclean
	@$(MAKE) clean -s -C $(LIBFT)
	@echo "Cleaned libft."
	@$(MAKE) clean -s -C $(MLX)
	@echo "Cleaned MLX."	
fclean: localclean
	@$(MAKE) fclean -s -C $(LIBFT)
	@echo "Fully cleaned libft."
	@$(MAKE) clean -s -C $(MLX)
	@echo "Cleaned MLX."
	@$(RM) $(NAME)
	@echo "Removed executable."

re: fclean all

.PHONY: all clean fclean re localclean
