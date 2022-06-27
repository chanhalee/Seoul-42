#include "./so_long.h"
#include <mlx.h>

int main(int argc, char **argv)
{
	t_map	map;
	void 	*mlx_ptr;

	mlx_ptr = mlx_init();
	if(mlx_ptr == 0)
		emergency_exit(NULL, TYPE_ERR_CODE_MLX);
	
	init_map(&map);
	parse_map(argv[1], &map);
	mlx_new_window(mlx_ptr, 300, 300, "SO_LONG");
	mlx_loop(mlx_ptr);
	return (0);
}
//gcc -lmlx -framework OpenGl -framework AppKit -Imlx *.c -o tes;./tes ./map.ber