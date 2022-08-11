/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:00:36 by leonard           #+#    #+#             */
/*   Updated: 2022/08/11 18:25:26 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_philo	*create_philos(t_rules *rules)
{
	size_t		i;
	t_philo		*philos;

	i = 0;
	philos = malloc(sizeof(t_philo) * rules->philo_nb);
	if (!philos)
		return (NULL);
	while (i < rules->philo_nb)
	{
		philos[i].rules = rules;
		philos[i].id = i + 1;
		philos[i].times_has_eaten = 0;
		pthread_mutex_init(&philos[i].m_time_eat, NULL);
		i++;
	}
	rules->philos = philos;
	rules->program_run = true;
	return (philos);
}

void	assign_forks(t_philo *philos, pthread_mutex_t *forks, t_rules *rules)
{
	size_t	i;

	i = 0;
	while (i < rules->philo_nb)
	{
		if (i == 0)
		{
			philos[i].lfork = &forks[rules->philo_nb - 1];
			philos[i].rfork = &forks[0];
		}
		else
		{
			philos[i].lfork = &forks[i - 1];
			philos[i].rfork = &forks[i];
		}
		i++;
	}
	return ;
}

int	init_philos(t_rules *rules)
{
	size_t			i;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc (sizeof(pthread_mutex_t) * rules->philo_nb);
	if (!forks)
		return (1);
	rules->f = forks;
	while (i < rules->philo_nb)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			free(forks);
			return (1);
		}
		i++;
	}
	philos = create_philos(rules);
	if (!philos)
		return (1);
	assign_forks(philos, forks, rules);
	return (0);
}
