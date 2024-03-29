/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonard <leonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:06:57 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/08/06 18:08:12 by leonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

//initiates each philo thread
void	init_threads(t_args *args, t_philo *philos)
{
	size_t	i;

	i = 0;
	while (i < args->philo_nb)
	{
		pthread_create(&philos[i].thread, NULL, (void *)philo_loop, &philos[i]);
		pthread_detach(philos[i].thread);
		my_usleep(100);
		i++;
	}
	return ;
}

//end philo threads in case of end of program
void	close_threads(t_args *args, t_philo *philos)
{
	size_t	i;

	i = 0;
	while (i < args->philo_nb)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	return ;
}