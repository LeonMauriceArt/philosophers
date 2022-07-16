/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:21:31 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/06/29 18:46:02 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

pthread_mutex_t	*init_forks(t_args *args)
{
	int				i;
	pthread_mutex_t	*mutex_list;

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

void	assign_forks(t_philosopher *philos, pthread_mutex_t *forks, t_args *arg)
{
	int	i;

	i = 0;
	while (i < arg->philo_nb)
	{
		if (i == 0)
		{
			philos[i].left_fork = &forks[arg->philo_nb];
			philos[i].right_fork = &forks[0];
		}
		else
		{
			philos[i].left_fork = &forks[i - 1];
			philos[i].right_fork = &forks[i];
		}
		i++;
	}
	philos[i].left_fork = &forks[arg->philo_nb - 1];
	philos[i].right_fork = &forks[arg->philo_nb];
	return ;
}

t_philosopher	*init_philos(t_args *args)
{
	int				i;
	t_philosopher	*philos;
	pthread_mutex_t	*forks;

	i = 0;
	philos = malloc(args->philo_nb * sizeof(t_philosopher));
	forks = init_forks(args);
	if (forks == NULL)
	{
		error_msg("Mutex init error\n");
		return (NULL);
	}
	if (!philos)
		return (NULL);
	while (i < args->philo_nb)
	{
		philos[i].id = i + 1;
		philos[i].has_eaten = false;
		philos[i].is_sleeping = false;
		i++;
	}
	philos[args->philo_nb].id = -1;
	assign_forks(philos, forks, args);
	return (philos);
}
