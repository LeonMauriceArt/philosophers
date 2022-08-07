/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonard <leonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:10:15 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/08/07 20:31:49 by leonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*check_dead(void *p)
{
	t_philo	*philos;
	size_t	i;
	size_t	num_philo_full;

	philos = p;
	while (philos->rules->program_run)
	{
		num_philo_full = 0;
		i = -1;
		while (++i < philos->rules->philo_nb)
		{
			if (get_time() - philos[i].time_eat > philos->rules->time_to_die)
			{
				philo_log(&philos[i], "died");
				philos->rules->program_run = false;
				break ;
			}
			if (philos->rules->philo_nb_eat && \
				philos[i].times_has_eaten >= philos->rules->philo_nb_eat)
				num_philo_full++;
		}
		if (num_philo_full == philos->rules->philo_nb)
			philos->rules->program_run = false;
	}
	return (0);
}

void	init_threads(t_rules *rules, t_philo *p)
{
	size_t	i;

	i = 0;
	rules->start_time = get_time();
	while (i < rules->philo_nb)
	{
		p[i].time_eat = get_time();
		if (pthread_create(&p[i].thread, NULL, (void *)eat_loop, &p[i]))
			error_msg("Thread creation error\n");
		pthread_detach(p[i].thread);
		usleep(50);
		i++;
	}
	if (pthread_create(&rules->check_dead, NULL, check_dead, p))
		error_msg("Failed to create a thread\n");
	if (pthread_join(rules->check_dead, NULL))
		error_msg("Failed to join thread\n");
	i = 0;
	while (i < rules->philo_nb)
	{
		pthread_mutex_destroy(p->lfork);
		pthread_mutex_destroy(p->rfork);
		i++;
	}
	pthread_mutex_destroy(&rules->msg_display);
}

int	main(int ac, char *av[])
{
	t_rules			rules;

	if (ac < 5 || ac > 6)
		return (error_msg("Bad numbers of arguments\n"));
	rules = parsing(ac, av);
	if (!rules.correct_parsing)
		return (1);
	if (init_philos(&rules))
		return (1);
	init_threads(&rules, rules.philos);
	return (0);
}
