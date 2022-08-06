/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonard <leonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:49:45 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/08/06 18:08:27 by leonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <string.h>
# include <sys/time.h>
# include <errno.h>
# include <stdint.h>

typedef struct s_rules
{
	bool			program_run;
	size_t			nb_philo_full;
	pthread_mutex_t	msg_display;
	struct	timeval	start_time;
}	t_rules;

typedef struct s_args
{
	size_t		philo_nb;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		philo_nb_eat;
	bool		optional_arg;
	bool		correct_parsing;
}	t_args;

typedef struct s_philosopher
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	bool			has_eaten;
	bool			is_sleeping;
	bool			is_dead;
	size_t			times_has_eaten;
	size_t			time_elapsed;
	pthread_t		thread;
	t_rules			*rules;
	t_args			*args;
}	t_philo;

//utils functions
int				ft_atoi(const char *str);
bool			has_alpha(char *str);
int				error_msg(char *msg);
t_args			parsing(int ac, char *av[]);

//debug functions
void			display_philo_infos(t_philo *philos);

//main functions
t_philo			*init_philos(t_args *args, t_rules *rules);
void			*philo_loop(void *p);
void			init_threads(t_args *args, t_philo *philos);
void			close_threads(t_args *args, t_philo *philos);
uint64_t		get_timestamp(struct timeval t);
void			my_usleep(uint64_t time);
void			display_log(t_philo *philo, void (*f)(int, int));

//actions
void			take_forks(t_philo *philo);
void			eat(t_philo *philo);

//logs
void			log_fork(int timeMs, int philoId);
void			log_eating(int timeMs, int philoId);
void			log_sleeping(int timeMs, int philoId);
void			log_thinking(int timeMs, int philoId);
void			log_die(int timeMs, int philoId);

#endif
