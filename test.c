#include "./includes/minilibx-linux/mlx.h"
#include <stdio.h>

int main()
{
	int x = 0;
	int y = 0;
	void *mlxc = mlx_init();
	void *mlxw = mlx_new_window(mlxc, 900, 900, "  123");
	void *data = mlx_xpm_file_to_image(mlxc, "/home/shrimech/goinfre/dev/cube3d/maps/orange.xpm",&x, &y);
	printf("%p\n", data);
	mlx_loop(mlxc);
	return 0;
}
