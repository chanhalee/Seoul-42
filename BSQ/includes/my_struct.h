//
// Created by LCH on 2021/09/27.
//

#ifndef MY_STRUCT_H
# define MY_STRUCT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_dot
{
	int				row;
	int				col;
	struct s_dot	*next;
}	t_dot;

typedef struct s_square
{
	int		size;
	t_dot	location;
}	t_square;

typedef struct s_map
{
	char		empty_c;
	char		obstacle_c;
	char		square_c;
	int			size_col;
	int			size_row;
	t_square	square;
	t_dot		*obstacle_head;
	t_dot		*front_line;
}	t_map;

# define TRUE (1)
# define FALSE (0)
# define ERR (-1)

void	map_init(t_map **map);
void	save_obstacle(t_dot **front_line, int row, int col);
void	search(t_map *map);
void	search_sub(int *prev_line, int *current_line, t_map *map, int index_y);
void	search_switch(int *curr, int *prev, int size); ///*
int		search_merge(int *prev_line, int *current_line, int index_x);
void	search_sizeup(t_square *old, int new_size, int new_x, int new_y);
int		save_first(int fd, t_map *map);
int		read_first(int fd, char *buf);
int		check_file(char *file_name, t_map *map);
int		check_all(int fd, t_map *map);
int		check_line(int fd, t_map *map, int y_counter);
void	print(t_map *map);
void	print_inner(t_map *map, int xs, int xe, int ys);
int		check_char(char c, t_map *map, int x_counter, int y_counter);
int		set_g_x_counter(int x_counter, t_map *map);
void	set_buf(char *buf, char c);

#endif //MY_STRUCT_H
