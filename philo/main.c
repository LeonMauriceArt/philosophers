/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonard <leonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:47:33 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/08/06 18:09:33 by leonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_dead(t_philo *philos, t_args args)
{
	size_t	i;

	i = 0;
	while (i < args.philo_nb)
	{
		if (philos[i].is_dead == true)
		{
			philos[i].rules->program_run = false;
			return ;
		}
		else
			i++;
	}
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

//main function
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
	gettimeofday(&rules.start_time, NULL);
	init_threads(&args, philos);
	while (1)
	{
		check_dead(philos);
		if (rules.nb_philo_full == args.philo_nb)
			rules.program_run = false;
		if (rules.program_run == false)
		{
			printf("-------SIMULATION MUST END-------/n");
			close_threads(&args, philos);
			return (0);
		}
	}
	return (0);
}
