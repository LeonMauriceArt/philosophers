/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonard <leonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:11:05 by lmaurin           #+#    #+#             */
/*   Updated: 2022/08/07 20:25:03 by leonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	philo_log(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->rules->msg_display);
	if (philo->rules->program_run)
		printf("%ld %d %s\n", get_time() - philo->rules->start_time, \
					philo->id, msg);
	pthread_mutex_unlock(&philo->rules->msg_display);
}

void	*eat_loop(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (p->rules->program_run)
	{
		philo_log(p, "is thinking");
		pthread_mutex_lock(p->lfork);
		philo_log(p, "has taken a fork");
		pthread_mutex_lock(p->rfork);
		philo_log(p, "has taken a fork");
		philo_log(p, "is eating");
		my_usleep(p->rules->time_to_eat, p->rules);
		p->time_eat = get_time();
		pthread_mutex_unlock(p->lfork);
		pthread_mutex_unlock(p->rfork);
		if (p->rules->program_run)
			p->times_has_eaten++;
		philo_log(p, "is sleeping");
		my_usleep(p->rules->time_to_sleep, p->rules);
	}
	return (0);
}
