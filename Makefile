NAME = fdf
FLAGS = -Wall -Werror -Wextra
CC = gcc

SRC_FILES = main.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Folders
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/

# Detect an add flag depend OS
detected_OS := $(shell uname -s)

ifeq ($(detected_OS),Darwin) 
	MLXM_DIR = ./minilibx_opengl/ 
	MINLBXM  = $(addprefix $(MLXM_DIR), libmlx.a) 
	MLXFAGS = -lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(detected_OS),Linux) 
	MLXM_DIR = ./mlxlinux/ 
	MINLBXM  = $(addprefix $(MLXM_DIR), libmlx.a) 
	MLXFAGS = -Lmlx_linux -lmlx_linux -L/usr/lib -Imlxlinux -lXext -lX11 -lm -lz 
endif

# Paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

LNK  = -L $(LIBFT_DIR) -lft -L $(MLXM_DIR) $(MLXFLAGS)

all: obj $(LIBFT) $(MINLBXM) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(MLXM_DIR) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
$(LIBFT):
	@make -C $(LIBFT_DIR)
$(MINLBXM):
	@make -C $(MLXM_DIR)

$(NAME): $(OBJ)
	gcc $(OBJ) $(LNK) -lm -o $(NAME)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLXM_DIR) clean

re: fclean all

.PHONY: all clean fclean re
