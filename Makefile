# mlx library Mac
MLXM		= ./minilibx_mms/
MLXM_LIB	= $(addprefix $(MLXM),mlx.a)
MLXM_INC	= -I ./minilibx_mms
MLXM_LNK	= -L ./minilibx_mms -l mlx -framework OpenGL -framework AppKit

# mlx library Linux
MLXL		= ./minilibx_opengl/
MLXL_LIB	= $(addprefix $(MLXM),mlx.a)
MLXL_INC	= -I ./minilibx_opengl
LXL_LNK		= -L ./minilibx_opengl -l mlx -framework OpenGL -framework AppKit

