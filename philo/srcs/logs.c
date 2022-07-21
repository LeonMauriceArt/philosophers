/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:54:07 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/07/21 17:09:28 by lmaurin-         ###   ########.fr       */
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

//a function for each log display
void	log_fork(int timeMs, int philoId)
{
	printf("%d %d has taken a fork\n", timeMs, philoId);
}

void	log_eating(int timeMs, int philoId)
{
	printf("%d %d is eating\n", timeMs, philoId);
}

void	log_sleeping(int timeMs, int philoId)
{
	printf("%d %d is sleeping\n", timeMs, philoId);
}

void	log_thinking(int timeMs, int philoId)
{
	printf("%d %d is thinking\n", timeMs, philoId);
}

void	log_die(int timeMs, int philoId)
{
	printf("%d %d died\n", timeMs, philoId);
}
