#ifndef SO_LONG_H
#define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./mlx/mlx.h"

#  define BUFFER_SIZE 99
# define TYPE_ERR_CODE_MALLOC 1
# define TYPE_ERR_CODE_FILE 2
# define TYPE_ERR_CODE_MAP 3
# define TYPE_ERR_CODE_MLX 3
# define TYPE_NEW_LINE 1
# define TYPE_NULL 0
# define TYPE_TRUE 1
# define TYPE_FALSE 0
# define TYPE_OBJECT_STATE_INITIAL 1
# define TYPE_OBJECT_STATE_COLLECTED 1
# define TYPE_MOVE_UP 10
# define TYPE_MOVE_LEFT 20
# define TYPE_MOVE_RIGHT 30
# define TYPE_MOVE_DOWN 40
# define TYPE_RESULT_CAUGHT 100
# define TYPE_RESULT_BLOCKED 200
# define TYPE_RESULT_MOVED 300
# define TYPE_RESULT_COLLECTED 400

typedef struct s_length
{
	int		type;
	size_t	len;
}	t_length;

typedef struct s_pos
{
	size_t			x;
	size_t			y;
	int				state;
	struct s_pos	*next;
} t_pos;

typedef struct s_user_state
{
	int				state;
	struct s_pos	pos;
} t_user_state;

typedef struct s_mlx_data
{
	void 	*mlx;
	void	*win;
	void	*run0;
	void	*run1;
	void	*run2;
	void	*run3;
	void	*run4;
	void	*run5;
	void	*idle0;
	void	*idle1;
	void	*idle2;
	void	*idle3;
	void	*idle4;
	void	*idle5;
	void	*grass;
	void	*exit_open;
	void	*chest_open;
	void	*chest_closed;
	void	*wall;
} t_mlx_data;


typedef struct s_map
{
	size_t				size_x;
	size_t				size_y;
	size_t				movement_count;
	size_t				collecible_count;
	struct s_user_state	user;
	struct s_pos		*obstacles;
	struct s_pos		*enemies;
	struct s_pos		*collectibles;
	struct s_pos		*exits;
} t_map;


char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_my_strlen(const char *s, t_length *result);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memset(void *b, int c, size_t len);
int			read_data_subsidiary(int fd, char **pending, char **buffer);
char		*read_data(int fd, char **pending, char *buffer);
char		*get_next_line(int fd);
void		emergency_exit(t_map *map, int exit_code);
void		print_error_and_exit(int exit_code);
size_t		ft_strlen(const char *s);
t_pos		*forge_collectibles(size_t pos_x, size_t pos_y, t_map *map);
t_pos		*forge_obstacle(size_t pos_x, size_t pos_y, t_map *map);
t_pos		*forge_ememy(size_t pos_x, size_t pos_y, t_map *map);
t_pos		*forge_exit(size_t pos_x, size_t pos_y, t_map *map);
void		init_map(t_map *map);
void		parse_map(char *file_name, t_map *map);
int			check_only_wall_in_line(char *line);
int check_matching_entry(t_pos *entry, int x, int y);
int			move_position(t_map* map, int move);
void		printmap(t_map *map);
void	mlx_asset_init(t_mlx_data *mlx_data);
void	mlx_make_rander(t_mlx_data *mlx, t_map *map);

#endif