/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:10:15 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/07/26 14:51:07 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*init_philos(t_all *all)
{
	size_t		i;
	t_philo		*philos;

	i = 0;
	philos = malloc(sizeof(t_philo) * all->args.philo_nb);
	if (!philos)
		return (NULL);
	while (i < all->args.philo_nb)
	{
		philos[i].all = all;
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

int	main(int ac, char *av[])
{
	t_all	all;
	t_philo	*philos;

	all.args = parsing(ac, av);
	if (all.args.correct_parsing == false)
		return (1);
	philos = init_philos(&all);
	for (int i = 0; i < all.args.philo_nb; i++)
	{
		printf("philo id %d exist\n", philos[i].id);
	}
	return (0);
}
