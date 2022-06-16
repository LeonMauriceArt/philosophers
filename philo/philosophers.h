/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:49:45 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/06/16 12:15:47 by lmaurin-         ###   ########.fr       */
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

typedef struct s_args
{
	int		philo_nb;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		philo_nb_eat;
	bool	optional_arg;
}	t_args;

typedef struct s_philosopher
{
	bool	is_dead;
	bool	is_eating;
	bool	is_sleeping;
	bool	is_thinking;
}	t_philosopher;

//utils functions
int		ft_atoi(const char *str);
bool	has_alpha(char *str);
void	error_msg(char *msg);
t_args	parsing(int ac, char *av[]);

//main functions
void	philo_loop(t_args *args);

#endif
