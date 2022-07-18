/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:31:51 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/07/18 17:45:01 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

//handles the log display and prevent messages overlaping
void	display_log(t_philo philo, void (*f)(int, int))
{
	pthread_mutex_lock(&philo.rules->msg_display);
	
	return ;
}

//main function for each philo thread
void	*philo_loop(void *p)
{
	t_philo			*philo;
	size_t			time_elapsed;

	philo = (t_philo *)p;
	time_elapsed = 0;
	while (1)
	{
		
	}
	return ;
}
