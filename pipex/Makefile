NAME		=	pipex
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

HEADER_SRCS	=	pipex.h pipex_bonus.h
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

SPATH_SRCS	=	pipex.c childs.c err.c free.c
SPATH_DIR	=	srcs/
SPATH		=	$(addprefix $(SPATH_DIR), $(SPATH_SRCS))
OBJ_S		=	$(SPATH:.c=.o)

BPATH_SRCS	=	pipex_bonus.c err_bonus.c here_doc_bonus.c\
				fds_bonus.c free_bonus.c child_bonus.c
BPATH_DIR	=	srcs_bonus/
BPATH		=	$(addprefix $(BPATH_DIR), $(BPATH_SRCS))
OBJ_B		=	$(BPATH:.c=.o)

LFT_SRCS	=	ft_strncmp.c ft_strdup.c ft_split.c ft_strjoin.c
LFT_DIR	=	lft/
LFT 		=	$(addprefix $(LFT_DIR), $(LFT_SRCS))\
				gnl/get_next_line_utils.c gnl/get_next_line.c
OBJ_LFT		=	$(LFT:.c=.o)

%.o: %.c $(HEADER) Makefile
				${CC} ${FLAGS} -c $< -o $@

$(NAME):		$(OBJ_LFT) $(OBJ_S)
				@$(CC) $(OBJ_LFT) $(OBJ_S) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

bonus:			$(OBJ_LFT) $(OBJ_B)
				$(CC) $(OBJ_LFT) $(OBJ_B) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
				@$(RM) $(OBJ_S)
				@$(RM) $(OBJ_LFT)
				@$(RM) $(OBJ_B)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re


RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
