#include "./so_long.h"
#include <mlx.h>

int main(int argc, char **argv)
{
	t_map	map;
	void 	*mlx_ptr;
	void	*mlx_win;
	void	*run1;
	void	*run2;
	void	*run3;
	void	*run4;
	int		img_height;
	int		img_width;

	mlx_ptr = mlx_init();
	if(mlx_ptr == 0)
		emergency_exit(NULL, TYPE_ERR_CODE_MLX);
	init_map(&map);
	parse_map(argv[1], &map);

	mlx_win = mlx_new_window(mlx_ptr, 1000, 1500, "Hello world!");
	run1 = mlx_xpm_file_to_image(mlx_ptr, "./images/hobbit/run1.xpm", &img_width, &img_height);
	run2 = mlx_xpm_file_to_image(mlx_ptr, "./images/hobbit/run2.xpm", &img_width, &img_height);
	run3 = mlx_xpm_file_to_image(mlx_ptr, "./images/hobbit/run3.xpm", &img_width, &img_height);
	run4 = mlx_xpm_file_to_image(mlx_ptr, "./images/hobbit/run4.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx_ptr, mlx_win, run1, 0, 0);
	mlx_put_image_to_window(mlx_ptr, mlx_win, run1, 64, 64);
	mlx_put_image_to_window(mlx_ptr, mlx_win, run1, 64, 0);
	mlx_put_image_to_window(mlx_ptr, mlx_win, run1, 0, 64);
	mlx_loop(mlx_ptr);
	return (0);
}
//gcc -lmlx -framework OpenGl -framework AppKit -Imlx *.c -o tes;./tes ./map.ber