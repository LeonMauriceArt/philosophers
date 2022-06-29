/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:21:31 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/06/28 13:41:30 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

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

t_philosopher	*init_philos(t_args *args, pthread_mutex_t *forks)
{
	int				i;
	t_philosopher	*philos;

	i = 0;
	philos = malloc(args->philo_nb * sizeof(t_philosopher));
	if (!philos)
		return (NULL);
	while (i < args->philo_nb)
	{
		philos[i].id = i + 1;
		philos[i].has_eaten = false;
		philos[i].is_sleeping = false;
		i++;
	}
	assign_forks(philos, forks, args);
	return (philos);
}
