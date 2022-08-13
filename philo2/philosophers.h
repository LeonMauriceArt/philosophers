/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonard <leonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:49:45 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/08/13 17:09:52 by leonard          ###   ########.fr       */
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

typedef struct s_philosopher
{
	int				id;
	uint64_t		time_eat;
	size_t			times_has_eaten;
	pthread_t		thread;
	struct s_rules	*rules;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
}	t_philo;

typedef struct s_rules
{
	size_t			philo_nb;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			philo_nb_eat;
	uint64_t		start_time;
	bool			optional_arg;
	bool			correct_parsing;
	bool			program_run;
	pthread_mutex_t	msg_display;
	t_philo			*philos;
	pthread_mutex_t	*f;
	pthread_mutex_t	mutex_time;
	pthread_mutex_t	mutex_program;
	pthread_mutex_t	mutex_time_eat;
}	t_rules;

//srcs
t_rules		parsing(int ac, char *av[]);
int			init_philos(t_rules *rules);
void		*eat_loop(void *philo);	
void		philo_log(t_philo *philo, char *msg);
void		destroy_fork(t_philo *philo);

//utils
int			mutex_check_time(t_philo *p, char c);
int			mutex_check_time_eat(t_philo *p, char c);
int			mutex_check_program(t_rules *rules, char c);
int			ft_atoi(const char *str);
bool		has_alpha(char *str);
int			error_msg(char *msg);
uint64_t	get_time(void);
void		my_usleep(uint64_t amount, t_rules *rules);

#endif
