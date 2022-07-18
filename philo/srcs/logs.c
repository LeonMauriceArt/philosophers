/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:54:07 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/07/18 17:46:28 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

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
