/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin <lmaurin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:10:15 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/08/06 00:34:13 by lmaurin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*init_philos(t_rules *rules)
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
		pthread_mutex_init(&philos[i].fork, NULL);
		philos[i].has_eaten = false;
		philos[i].has_fork = false;
		philos[i].id = i + 1;
		philos[i].is_dead = false;
		philos[i].times_has_eaten = 0;
		i++;
	}
	return (philos);
}

void	init_all(t_rules *rules, t_philo *philos)
{
	rules->philos = philos;
	rules->nb_philo_full = 0;
	rules->program_run = true;
}

void	check_dead(t_rules *rules)
{
	size_t	i;

	i = 0;
	while (i < rules->philo_nb)
	{
		if(rules->philos[i].is_dead == true)
		{
			rules->program_run = false;
			break;
		}
		i++;
	}
}

void	init_threads(t_rules *rules, t_philo *philos)
{
	size_t	i;

	i = 0;
	while (i < rules->philo_nb)
	{
		pthread_create(&philos[i].thread, NULL, (void *)philo_thread, &philos[i]);
		pthread_detach(philos[i].thread);
		usleep(100);
		i++;
	}
	return ;
}

int	main(int ac, char *av[])
{
	t_rules	rules;
	t_philo	*philos;

	rules = parsing(ac, av);
	if (rules.correct_parsing == false)
		return (1);
	philos = init_philos(&rules);
	for (size_t i = 0; i < rules.philo_nb; i++)
	{
		printf("philo id %d exist\n", philos[i].id);
	}
	return (0);
}
