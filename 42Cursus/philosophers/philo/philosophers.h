/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:12:28 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/28 14:51:20 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

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
# define TYPE_STATE_DEAD -1

typedef struct s_philosopher
{
	pthread_t				tid;
	int						number;
	pthread_mutex_t			*l_fork;
	pthread_mutex_t			*r_fork;
	pthread_mutex_t			*permission_to_speak;
	int						*speakable;
	int						state;
	pthread_mutex_t			state_mutex;
	struct timeval			last_eat;
	struct timeval			starting_time;
	int						eat_count;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						*number_of_full;
	int						number_of_philos;
	struct s_philosopher	*next;
	struct s_philosopher	*prev;
}	t_philosopher;

typedef struct s_bigbro
{
	struct s_philosopher	*philosophers_head;
	struct s_philosopher	*philosophers_tail;
	pthread_mutex_t			*forks;
	pthread_mutex_t			permission_to_speak;
	int						speakable;
	int						number_of_philos;
	int						number_of_full;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						mandatory_eat_count;
}	t_bigbro;

int			ft_atoi(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			philosopher_thread_create(t_bigbro *bigbro);
int			philosopher_thread_main(t_philosopher *philo);
long long	ft_get_time_gap(struct timeval tv);
int			init_bigbro_data(t_bigbro *bigbro, char **argv);
int			create_philosopher_data(t_bigbro *bigbro);
int			free_all_philosopher_data(t_bigbro *bigbro);
void		clear_bigbro_data(t_bigbro *bigbro);
int			philo_get_state(t_philosopher *philo);
int			philo_set_state(t_philosopher *philo, int state);
void		set_starting_time(t_bigbro *bigbro, struct timeval tv);
void		philo_broadcast_state(t_philosopher *philo, char *str, int silence);
int			philo_terminate(t_philosopher *philo);
int			check_philo_vital(t_philosopher *philo, int silence);
int			bigbro_set_philo_done(t_philosopher *philo);
int			check_vital_while_sleep(t_philosopher *philo, struct timeval start, long long sleep_time);
int			single_philo_action(t_philosopher *philo);

#endif