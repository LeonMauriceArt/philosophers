/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:06:57 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/07/18 17:45:53 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

//initiates each philo thread
void	init_threads(t_args *args, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < args->philo_nb)
	{
		pthread_create(&philos[i].thread, NULL, (void *)philo_loop, &philos[i]);
		i++;
		usleep(200);
	}
	return ;
}

//end philo threads in case of end of program
void	close_threads(t_args *args, t_philo *philos)
{
	
}