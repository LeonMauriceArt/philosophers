/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:49:45 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/07/18 19:14:38 by lmaurin-         ###   ########.fr       */
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

typedef struct s_rules
{
	bool			program_run;
	size_t			time_elapsed;
	pthread_mutex_t	msg_display;
}	t_rules;

typedef struct s_args
{
	int		philo_nb;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		philo_nb_eat;
	bool	optional_arg;
	bool	correct_parsing;
}	t_args;

typedef struct s_philosopher
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	bool			has_eaten;
	bool			is_sleeping;
	int				times_has_eaten;
	pthread_t		thread;
	t_rules			*rules;
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
size_t			get_timestamp(void);
void			my_usleep(int time);

//logs
void			log_fork(int timeMs, int philoId);
void			log_eating(int timeMs, int philoId);
void			log_sleeping(int timeMs, int philoId);
void			log_thinking(int timeMs, int philoId);
void			log_die(int timeMs, int philoId);

#endif
