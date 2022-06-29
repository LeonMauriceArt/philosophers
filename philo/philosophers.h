/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:49:45 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/06/28 16:28:36 by lmaurin-         ###   ########.fr       */
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
	pthread_t		thread;
}	t_philosopher;

//utils functions
int				ft_atoi(const char *str);
bool			has_alpha(char *str);
int				error_msg(char *msg);
t_args			parsing(int ac, char *av[]);

//debug functions
void	display_philo_infos(t_philosopher *philos);

//main functions
t_philosopher	*init_philos(t_args *args, pthread_mutex_t *forks);
void			*philo_loop(t_philosopher philo);

#endif
