/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonard <leonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:17:13 by leonard           #+#    #+#             */
/*   Updated: 2022/08/13 16:23:58 by leonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	mutex_check_program(t_rules *rules, char c)
{
	if (c == 'w')
	{
		pthread_mutex_lock(&rules->mutex_program);
		rules->program_run = false;
		pthread_mutex_unlock(&rules->mutex_program);
		return (0);
	}
	else if (c == 'r')
	{
		pthread_mutex_lock(&rules->mutex_program);
		if (rules->program_run)
		{
			pthread_mutex_unlock(&rules->mutex_program);
			return (0);
		}
		pthread_mutex_unlock(&rules->mutex_program);
		return (1);
	}
	return (0);
}

int	mutex_check_time_eat(t_philo *p, char c)
{
	if (c == 'w')
	{
		pthread_mutex_lock(&p->rules->mutex_time_eat);
		p->times_has_eaten++;
		pthread_mutex_unlock(&p->rules->mutex_time_eat);
		return (0);
	}
	else if (c == 'r')
	{
		pthread_mutex_lock(&p->rules->mutex_time_eat);
		if (p->times_has_eaten == p->rules->philo_nb_eat)
		{
			pthread_mutex_unlock(&p->rules->mutex_time_eat);
			return (0);
		}
		pthread_mutex_unlock(&p->rules->mutex_time_eat);
		return (1);
	}
	return (0);
}

int	mutex_check_time(t_philo *p, char c)
{
	if (c == 'w')
	{
		pthread_mutex_lock(&p->rules->mutex_time);
		p->time_eat = get_time();
		pthread_mutex_unlock(&p->rules->mutex_time);
		return (0);
	}
	else if (c == 'r')
	{
		pthread_mutex_lock(&p->rules->mutex_time);
		if (get_time() - p->time_eat > p->rules->time_to_die)
		{
			pthread_mutex_unlock(&p->rules->mutex_time);
			return (0);
		}
		pthread_mutex_unlock(&p->rules->mutex_time);
		return (1);
	}
	return (0);
}
