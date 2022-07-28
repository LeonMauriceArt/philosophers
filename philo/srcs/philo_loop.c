/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:31:51 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/07/28 18:04:53 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

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
