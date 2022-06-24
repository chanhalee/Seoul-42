#ifndef SO_LONG_H
#define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

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
} t_map;


void	emergency_exit(t_map *map, int exit_code);

#endif