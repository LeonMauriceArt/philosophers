/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:47:33 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/07/21 16:09:43 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_philos(t_philo *philo)
{
	size_t	i;

	i = 0;
	while (i < philo[0].args->philo_nb)
	{
		pthread_mutex_unlock(philo[i].left_fork);
		pthread_mutex_unlock(philo[i].right_fork);
		pthread_mutex_destroy(philo[i].left_fork);
		pthread_mutex_destroy(philo[i].right_fork);
	}
	free(philo);
	return ;
}

//initiate rules struct
void	init_rules(t_rules *rules)
{
	rules->program_run = true;
	rules->nb_philo_full = 0;
	pthread_mutex_init(&rules->msg_display, NULL);
	return ;
}

//main function, execute parsing and thread init, and check for program_run var
int	main(int ac, char *av[])
{
	t_rules				rules;
	t_args				args;
	t_philo				*philos;

	init_rules(&rules);
	if (ac < 5 || ac > 6)
		return (0);
	args = parsing(ac, av);
	if (args.correct_parsing == false)
		return (-1);
	philos = init_philos(&args, &rules);
	init_threads(&args, philos);
	while (1)
	{
		one_dead(philos);
		if (rules.nb_philo_full == args.philo_nb_eat)
			rules.program_run = false;
		// printf("after one dead main\n");
		if (rules.program_run == false)
		{
			printf("-------SIMULATION MUST END-------/n");
			close_threads(&args, philos);
			free_philos(philos);
			return (0);
		}
	}
	return (0);
}
