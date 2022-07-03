/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:35:16 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/03 21:32:11 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

# define BUFFER_SIZE 99
# define TYPE_ERR_CODE_MALLOC 1
# define TYPE_ERR_CODE_FILE 2
# define TYPE_ERR_CODE_MAP 3
# define TYPE_ERR_CODE_MLX 4
# define TYPE_CLEAN_QUIT 0
# define TYPE_NEW_LINE 1
# define TYPE_NULL 0
# define TYPE_TRUE 1
# define TYPE_FALSE 0
# define TYPE_OBJECT_STATE_INITIAL 0
# define TYPE_OBJECT_STATE_COLLECTED 1
# define TYPE_MOVE_UP 13
# define TYPE_MOVE_LEFT 0
# define TYPE_MOVE_RIGHT 2
# define TYPE_MOVE_DOWN 1
# define TYPE_RESULT_CAUGHT 100
# define TYPE_RESULT_BLOCKED 200
# define TYPE_RESULT_MOVED 300
# define TYPE_RESULT_COLLECTED 400
# define TYPE_KEY_A 0
# define TYPE_KEY_S 1
# define TYPE_KEY_D 2
# define TYPE_KEY_W 13
# define TYPE_KEY_ESC 53

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
}	t_pos;

typedef struct s_user_state
{
	int				state;
	struct s_pos	pos;
}	t_user_state;

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
}	t_map;

typedef struct s_mlx_data
{
	void			*mlx;
	void			*win;
	void			*run0;
	void			*run1;
	void			*run2;
	void			*run3;
	void			*run4;
	void			*run5;
	void			*idle_down;
	void			*idle_up;
	void			*idle_left;
	void			*idle_right;
	void			*enemy_down;
	void			*enemy_up;
	void			*enemy_left;
	void			*enemy_right;
	void			*grass;
	void			*exit;
	void			*c_open;
	void			*c_closed;
	void			*wall;
	struct s_map	map;
}	t_mlx_data;

char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_my_strlen(const char *s, t_length *result);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memset(void *b, int c, size_t len);
int			read_data_subsidiary(int fd, char **pending, char **buffer);
char		*read_data(int fd, char **pending, char *buffer);
char		*get_next_line(int fd);
void		emergency_exit_bonus(t_map *map, int exit_code);
void		print_error_and_exit(int exit_code);
size_t		ft_strlen(const char *s);
t_pos		*forge_collectibles(size_t pos_x, size_t pos_y, t_map *map);
t_pos		*forge_obstacle(size_t pos_x, size_t pos_y, t_map *map);
t_pos		*forge_ememy(size_t pos_x, size_t pos_y, t_map *map);
t_pos		*forge_exit(size_t pos_x, size_t pos_y, t_map *map);
void		init_map(t_map *map);
void		parse_map(char *file_name, t_map *map);
int			check_only_wall_in_line(char *line);
int			check_matching_entry(t_pos *entry, size_t x, size_t y);
t_pos		move_position(t_map *map, int move);
void		mlx_asset_init(t_mlx_data *mlx_data);
void		mlx_make_render(t_mlx_data *mlx);
int			mlx_key_up(int keycode, t_mlx_data *mlx);
int			mlx_key_down(int keycode, t_mlx_data *mlx);
void		mlx_set_user_img(t_mlx_data *mlx);
void		ft_putnbr_custom(int n);
int			mlx_cleanup(t_mlx_data *mlx);
int			get_object_state(t_pos *entry, size_t x, size_t y);
void		check_enemy_capture(t_mlx_data *mlx);
void		move_enemies(t_mlx_data *mlx);
char		*ft_itoa_custom(int n);

#endif