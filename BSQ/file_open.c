#include "library/my_struct.h"


void	save_first(int fd, t_map *map)
{
	char	buf[3];

	map -> size_col = read_first(fd, buf);
	map -> empty_c = buf[0];
	map -> obstacle_c = buf[1];
	map -> square_c = buf[2];
}

int	read_first(int fd, char *buf)
{
	int		i;
	int		col;
	char	c;

	col = 0;
	i = 0;
	while (i < 3)
	{
		read(fd, &c, 1);
		buf[i++] = c;
	}
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		col = (col * 10) + buf[0] - 48;
		buf[0] = buf[1];
		buf[1] = buf[2];
		buf[2] = c;
	}
	return (col);
}

void	read_obstacle(int fd, t_map *map)
{
	int		y_counter;
	char	c;

	y_counter = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
	}
	while (read_line(fd, map, y_counter))
		y_counter++;
}

int	read_line(int fd, t_map *map, int y_counter)
{
	char	c;
	int		x_counter;

	x_counter = 0;
	if (read(fd, &c, 1))
	{
		if (c == '\n')
			return (1);
		if (c == (map -> obstacle_c))
			save_obstacle(&(map -> front_line), x_counter, y_counter);
		x_counter++;
		while (read(fd, &c, 1))
		{
			if (c == '\n')
				return (1);
			if (c == (map -> obstacle_c))
				save_obstacle(&(map -> front_line), x_counter, y_counter);
			x_counter++;
		}
	}
	return (0);
}

int	open_file(char *file_name,	t_map *map)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	read_obstacle(fd, map);
	close (fd);
	return (0);
}
