#include "graphic.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	char	*s;
	
	s = "HELLO";

	ft_strlen (s);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
