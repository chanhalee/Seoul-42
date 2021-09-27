#include "library/my_struct.h"
#include <stdio.h>
static int	g_x_check;

void	check_all(int fd, t_map *map)
{
	int	y_counter;

	y_counter = 0;
	while (check_line(fd, map, y_counter))
		y_counter++;
	if (y_counter  != map -> size_col)
		write(2, "map error\n", 11);
}

int	check_line(int fd, t_map *map, int y_counter)
{
	char	c;
	int		x_counter;

	x_counter = 0;
	if (read(fd, &c, 1))
	{
		x_counter = check_c_map(map, c, x_counter);
		while (read(fd, &c, 1))
		{
			if (c == '\n')
				break ;
			x_counter = check_c_map(map, c, x_counter);
		}
		if (g_x_check == 0)
		{
			g_x_check = x_counter;
			map -> size_row = x_counter;
		}
		if (x_counter != g_x_check)
			write(1, "map error", 10);
		return (1);
	}
	return (0);
}

int	check_c_map(t_map *map, char c, int count)
{
	if (c == (map -> empty_c) || c == (map -> obstacle_c))
		count++;
	else
		write(1, "map error", 10);
	return (count);
}

int	check_file(char *file_name, t_map *map)
{
	int	fd;

	g_x_check = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write(2, "map error", 10);
		return (0);
	}
	save_first(fd, map);
	check_all(fd, map);
	close (fd);
	return (0);
}
