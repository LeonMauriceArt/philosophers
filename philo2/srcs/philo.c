/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonard <leonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:11:05 by lmaurin           #+#    #+#             */
/*   Updated: 2022/08/13 17:11:42 by leonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	philo_log(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->rules->msg_display);
	if (!mutex_check_program(philo->rules, 'r'))
		printf("%lu %d %s\n", get_time() - philo->rules->start_time, \
					philo->id, msg);
	pthread_mutex_unlock(&philo->rules->msg_display);
}

void	take_forks(t_philo *p)
{
	if (!mutex_check_program(p->rules, 'r'))
	{
		pthread_mutex_lock(p->lfork);
		philo_log(p, "has taken a fork");
		pthread_mutex_lock(p->rfork);
		philo_log(p, "has taken a fork");
		philo_log(p, "is eating");
		my_usleep(p->rules->time_to_eat, p->rules);
		mutex_check_time(p, 'w');
		pthread_mutex_unlock(p->lfork);
		pthread_mutex_unlock(p->rfork);
	}
}

void	destroy_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_destroy(philo->rfork);
}

void	*eat_loop(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (!mutex_check_program(p->rules, 'r'))
	{
		philo_log(p, "is thinking");
		if (!mutex_check_program(p->rules, 'r'))
			take_forks(philo);
		if (!mutex_check_program(p->rules, 'r'))
			mutex_check_time_eat(p, 'w');
		philo_log(p, "is sleeping");
		my_usleep(p->rules->time_to_sleep, p->rules);
	}
	return (0);
}
