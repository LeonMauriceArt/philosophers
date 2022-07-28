/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:21:31 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/07/28 15:08:26 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

//initiate all forks mutexes
pthread_mutex_t	*init_forks(t_args *args)
{
	size_t				i;
	pthread_mutex_t		*mutex_list;

	i = 0;
	mutex_list = malloc(args->philo_nb * sizeof(pthread_mutex_t));
	if (!mutex_list)
		return (NULL);
	while (i < args->philo_nb)
	{
		if (pthread_mutex_init(&mutex_list[i], NULL) != 0)
		{
			free(mutex_list);
			return (NULL);
		}
		i++;
	}
	return (mutex_list);
}

//assign the forks to each philosopher
void	assign_forks(t_philo *philos, pthread_mutex_t *forks, t_args *arg)
{
	size_t	i;

	i = 0;
	while (i < arg->philo_nb)
	{
		if (i == 0)
		{
			philos[i].left_fork = &forks[arg->philo_nb - 1];
			philos[i].right_fork = &forks[0];
		}
		else
		{
			philos[i].left_fork = &forks[i - 1];
			philos[i].right_fork = &forks[i];
		}
		i++;
	}
	return ;
}

//initiate a philosopher struct
void	init_struct(t_philo *philos, t_args *args, t_rules *rules)
{
	size_t	i;

	i = 0;
	while (i < args->philo_nb)
	{
		philos[i].id = i + 1;
		philos[i].times_has_eaten = 0;
		philos[i].has_eaten = false;
		philos[i].is_sleeping = false;
		philos[i].rules = rules;
		philos[i].args = args;
		philos[i].is_dead = false;
		i++;
	}
	philos[args->philo_nb].id = -1;
	return ;
}

//initiate all philosophers and assign them forks
t_philo	*init_philos(t_args *args, t_rules *rules)
{
	t_philo			*philos;
	pthread_mutex_t	*forks;

	philos = malloc(args->philo_nb * sizeof(t_philo));
	forks = init_forks(args);
	if (forks == NULL)
	{
		error_msg("Mutex init error\n");
		return (NULL);
	}
	if (!philos)
		return (NULL);
	init_struct(philos, args, rules);
	assign_forks(philos, forks, args);
	return (philos);
}
