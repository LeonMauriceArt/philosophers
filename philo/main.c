/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:47:33 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/06/28 16:29:07 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_threads(t_args *args, t_philosopher *philos)
{
	int	i;

	i = 0;
	while (i < args->philo_nb)
	{
		printf("TEST\n");
		pthread_create(&philos[i].thread, NULL, (void *)philo_loop, &philos[i]);
		i++;
	}
	return ;
}

pthread_mutex_t	*init_forks(t_args *args)
{
	int				i;
	pthread_mutex_t	*mutex_list;

	i = 0;
	mutex_list = malloc(args->philo_nb * sizeof(pthread_mutex_t));
	if (!mutex_list)
		return (NULL);
	while (i < args->philo_nb)
	{
		if (pthread_mutex_init(&mutex_list[i], NULL) != 0)
		{
			free(mutex_list);
			return (NULL);
		}
		i++;
	}
	return (mutex_list);
}

int	main(int ac, char *av[])
{
	t_args				args;
	pthread_mutex_t		*forks;
	t_philosopher		*philos;

	if (ac < 5 || ac > 6)
		return (0);
	args = parsing(ac, av);
	if (args.correct_parsing == false)
		return (1);
	forks = init_forks(&args);
	if (forks == NULL)
	{
		error_msg("Mutex init error\n");
		return (1);
	}
	philos = init_philos(&args, forks);
	display_philo_infos(philos);
	init_threads(&args, philos);
	return (0);
}
