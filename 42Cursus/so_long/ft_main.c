#include "./so_long.h"

int main(int argc, char **argv)
{
	t_map	map;
	t_mlx_data	mlx_data;

	mlx_data.mlx = mlx_init();
	if(mlx_data.mlx == 0)
		emergency_exit(NULL, TYPE_ERR_CODE_MLX);
	if(argc < 2)
		emergency_exit(NULL, TYPE_ERR_CODE_MLX);
	init_map(&map);
	parse_map(argv[1], &map);

	mlx_data.win = mlx_new_window(mlx_data.mlx, 16 * map.size_x, 16 * map.size_y, "Hello world!");
	mlx_asset_init(&mlx_data);
	mlx_make_rander(&mlx_data, &map);
	mlx_loop(mlx_data.mlx);
	return (0);
}
