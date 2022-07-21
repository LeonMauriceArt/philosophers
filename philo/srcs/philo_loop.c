/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:31:51 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/07/21 14:09:15 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

//handles the log display and prevent messages overlaping
void	display_log(t_philo *philo, void (*f)(int, int))
{
	pthread_mutex_lock(&philo->rules->msg_display);
	f(get_timestamp(), philo->id);
	pthread_mutex_unlock(&philo->rules->msg_display);
	return ;
}

//main function for each philo thread
void	*philo_loop(void *p)
{
	t_philo			*philo;

	philo = (t_philo *)p;
	while (1 && philo->is_dead != true)
	{
		take_forks(philo);
		eat(philo);
	}
	return (NULL);
}
