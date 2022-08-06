/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonard <leonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:53:12 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/08/06 18:06:11 by leonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	display_log(philo, log_fork);
	pthread_mutex_lock(philo->right_fork);
	display_log(philo, log_fork);
}

void	eat(t_philo *philo)
{
	display_log(philo, log_eating);
	if (philo->args->time_to_eat > philo->args->time_to_die)
	{
		usleep(philo->args->time_to_die * 1000);
		philo->is_dead = true;
		display_log(philo, log_die);
		return ;
	}
	usleep(philo->args->time_to_eat * 1000);
	philo->has_eaten = true;
	philo->times_has_eaten++;
	if (philo->times_has_eaten == philo->args->philo_nb_eat)
		philo->rules->nb_philo_full++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	display_log(philo, log_sleeping);
	usleep(philo->args->time_to_sleep * 1000);
	display_log(philo, log_thinking);
}
