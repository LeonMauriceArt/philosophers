/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:10:15 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/08/16 11:44:35 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_dead(t_rules *r)
{
	size_t	i;
	size_t	num_philo_full;

	num_philo_full = 0;
	while (r->program_run)
	{
		i = -1;
		while (++i < r->philo_nb)
		{
			if (!mutex_check_time(&r->philos[i], 'r'))
			{
				philo_log(&r->philos[i], "died");
				mutex_check_program(r, 'w');
				return ;
			}
			if (r->philo_nb_eat && !mutex_check_time_eat(&r->philos[i], 'r') \
					&& r->philos[i].times_has_eaten >= 0)
				num_philo_full++;
		}
		if (num_philo_full == r->philo_nb)
			mutex_check_program(r, 'w');
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

void	destroy_r_mutex(t_rules *rules)
{
	pthread_mutex_destroy(&rules->mutex_program);
	pthread_mutex_destroy(&rules->mutex_time);
	pthread_mutex_destroy(&rules->mutex_time_eat);
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
	while (++i < rules.philo_nb && rules.philo_nb != 1)
	{
		pthread_join(rules.philos[i].thread, NULL);
	}
	i = -1;
	while (++i < rules.philo_nb && rules.philo_nb != 1)
		destroy_fork(&rules.philos[i]);
	free (rules.philos);
	free (rules.f);
	destroy_r_mutex(&rules);
	return (0);
}
