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
MLXL_DIR = ./minilibx_opengl/
MLXM_DIR = ./minilibx_mms/

# Paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
MINLBXL  = $(addprefix $(MLXL_DIR), libmlx.a)
# MINLBXM  = $(addprefix $(MLXM_DIR), libmlx.dylib)

# mlx library Mac
# MLXM_INC	= -I ./minilibx_mms
# MLXM_LNK	= -L ./minilibx_mms -l mlx -framework OpenGL -framework AppKit

# mlx library Linux
# MLXL		= ./minilibx_opengl/
# MLXL_LIB	= $(addprefix $(MINLBXM),mlx.a)
# MLXL_INC	= -I ./minilibx_opengl
# LXL_LNK		= -L ./minilibx_opengl -l mlx -framework OpenGL -framework AppKit

LNK  = -L $(LIBFT_DIR) -lft -L $(MLXL_DIR) \
	   -lmlx -framework OpenGL -framework AppKit

all: obj $(LIBFT) $(MINLBXL) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(MLXL_DIR) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
$(LIBFT):
	@make -C $(LIBFT_DIR)
$(MINLBXL):
	@make -C $(MLXM_DIR)

$(NAME): $(OBJ)
	gcc $(OBJ) $(LNK) -lm -o $(NAME)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLXL_DIR) clean

re: fclean all

.PHONY: all clean fclean re
