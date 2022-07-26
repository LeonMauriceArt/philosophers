/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:49:45 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/07/26 14:49:58 by lmaurin-         ###   ########.fr       */
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
	pthread_mutex_t	fork;
	bool			has_fork;
	bool			has_eaten;
	bool			is_dead;
	size_t			times_has_eaten;
	size_t			time_snap;
	pthread_t		thread;
	struct s_all	*all;
}	t_philo;

typedef struct s_all
{
	bool			program_run;
	size_t			nb_philo_full;
	pthread_mutex_t	msg_display;
	t_philo			*philos;
	t_args			args;
}	t_all;

//srcs
t_args	parsing(int ac, char *av[]);

//utils
int		ft_atoi(const char *str);
bool	has_alpha(char *str);
int		error_msg(char *msg);

#endif
