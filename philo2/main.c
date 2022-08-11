/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonard <leonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:10:15 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/08/11 17:09:29 by leonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_dead(t_rules *r)
{
	size_t	i;
	size_t	num_philo_full;

	while (r->program_run)
	{
		num_philo_full = 0;
		i = -1;
		while (++i < r->philo_nb)
		{
			if (get_time() - r->philos[i].time_eat > r->time_to_die)
			{
				philo_log(&r->philos[i], "died");
				r->program_run = false;
				return ;
			}
			if (r->philo_nb_eat && r->philos[i].times_has_eaten \
					>= r->philo_nb_eat)
				num_philo_full++;
		}
		if (num_philo_full == r->philo_nb)
			r->program_run = false;
	}
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
		usleep(50);
		i++;
	}
}

int	main(int ac, char *av[])
{
	size_t	i;
	t_rules	rules;

	if (ac < 5 || ac > 6)
		return (error_msg("Bad numbers of arguments\n"));
	rules = parsing(ac, av);
	if (!rules.correct_parsing)
		return (1);
	if (init_philos(&rules))
		return (1);
	pthread_mutex_init(&rules.msg_display, NULL);
	init_threads(&rules, rules.philos);
	check_dead(&rules);
	i = -1;
	while (++i < rules.philo_nb)
		pthread_join(rules.philos[i].thread, NULL);
	return (0);
}
