/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:53:12 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/07/20 18:14:53 by lmaurin-         ###   ########.fr       */
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
	my_usleep((philo->args->time_to_eat) * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleep(t_philo *philo)
{
	display_log(philo, log_sleeping);
	my_usleep((philo->args->time_to_sleep) * 1000);
}

void	think(t_philo *philo)
{
	display_log(philo, log_thinking);
}
