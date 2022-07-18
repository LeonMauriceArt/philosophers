/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:47:33 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/07/18 17:50:33 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//initiate rules struct
void	init_rules(t_rules *rules)
{
	rules->program_run = true;
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
		if (rules.program_run == false)
		{
			close_threads(&args, philos);
			return (0);
		}
	}
	return (0);
}
