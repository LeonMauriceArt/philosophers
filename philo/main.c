/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:47:33 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/06/15 15:56:49 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	args_init(int ac, char *av[], t_args *args)
{
	args->philo_nb = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->philo_nb_eat = ft_atoi(av[5]);
	else
		args->philo_nb_eat = -1;
	return ;
}

int	main(int ac, char *av[])
{
	t_args	args;

	if (ac < 5 || ac > 6)
		return (0);
	args_init(ac, av, &args);
	printf("philo_nb = %d\n", args.philo_nb);
	printf("time_to_die = %d\n", args.time_to_die);
	printf("time_to_eat = %d\n", args.time_to_eat);
	printf("time_to_sleep = %d\n", args.time_to_sleep);
	printf("philo_nb_eat = %d\n", args.philo_nb_eat);
	return (0);
}
