/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonard <leonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:10:15 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/08/06 21:21:46 by leonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_dead(t_rules *rules)
{
	size_t	i;

	i = 0;
	while (i < rules->philo_nb)
	{
		if (rules->philos[i].is_dead == true)
		{
			rules->program_run = false;
			return (1);
		}
		i++;
	}
	return (0);
}

void	init_threads(t_rules *rules, t_philo *p)
{
	size_t	i;

	i = 0;
	while (i < rules->philo_nb)
	{
		pthread_create(&p[i].thread, NULL, (void *)philo_thread, &p[i]);
		pthread_detach(p[i].thread);
		usleep(100);
		i++;
	}
	return ;
}

int	main(int ac, char *av[])
{
	t_rules			rules;

	rules = parsing(ac, av);
	if (rules.correct_parsing == false)
		return (1);
	if (init_philos(&rules))
		return (1);
	init_threads(&rules, rules.philos);
	return (0);
}
