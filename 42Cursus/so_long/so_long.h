#ifndef SO_LONG_H
#define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

#  define BUFFER_SIZE 99
# define TYPE_ERR_CODE_MALLOC 1
# define TYPE_ERR_CODE_FILE 2
# define TYPE_ERR_CODE_MAP 3
# define TYPE_NEW_LINE 1
# define TYPE_NULL 0

typedef struct s_length
{
	int		type;
	size_t	len;
}	t_length;

typedef struct s_pos
{
	size_t			x;
	size_t			y;
	struct s_pos	*next;
} t_pos;

typedef struct s_user_state
{
	int				state;
	struct s_pos	pos;
} t_user_state;


typedef struct s_map
{
	size_t				size_x;
	size_t				size_y;
	struct s_user_state	user;
	struct s_pos		*obstacles;
	struct s_pos		*enemies;
	struct s_pos		*collectibles;
	struct s_pos		*exits;
} t_map;

char		*get_next_line(int fd);
void		emergency_exit(t_map *map, int exit_code);
void		print_error_and_exit(int exit_code);
size_t		ft_strlen(const char *s);
t_pos		*forge_collectibles(size_t pos_x, size_t pos_y, t_map *map);
t_pos		*forge_obstacle(size_t pos_x, size_t pos_y, t_map *map);
t_pos		*forge_ememy(size_t pos_x, size_t pos_y, t_map *map);
t_pos		*forge_exit(size_t pos_x, size_t pos_y, t_map *map);
t_map		*get_empty_map(void);
void		parse_map(char *file_name, t_map *map);
void		parse_line(char *line, t_map *map, size_t pos_y);
void		parse_block(char block, t_map *map, size_t pos_x, size_t pos_y);
int			check_only_wall_in_line(char *line);
void	printmap(t_map *map);

#endif