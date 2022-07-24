#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define TYPE_NOT_IN_USE 0
# define TYPE_IN_USE 1
# define TYPE_STATE_THINK 10
# define TYPE_STATE_EAT 20
# define TYPE_STATE_SLEEP 30


typedef struct s_philosopher
{
	pthread_mutex_t			l_fork;
	pthread_mutex_t			*r_fork;
	pthread_mutex_t			*permission_to_speak;
	int						last_eat;
	int						state;
	int						number;
	int						eat_count;
	struct s_philosopher	*next;
	struct s_philosopher	*prev;
}	t_philosopher;

typedef struct s_bigbro
{
	struct s_philosopher	*philosophers_head;
	struct s_philosopher	*philosophers_tail;
	pthread_mutex_t			permission_to_speak;
	int						number_of_philos;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						mandatory_eat_count;
}	t_bigbro;

int		ft_atoi(char *str);
int		init_system(t_bigbro *big_bro, char **argv);
int 	create_philosophers(t_bigbro *bigbro);
int		free_all_philosophers(t_bigbro *bigbro);

#endif