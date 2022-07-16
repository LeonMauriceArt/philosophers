/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:31:51 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/06/29 18:17:21 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*philo_loop(void *p)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)p;
	printf("In Thread\n");
	printf("I am philo number %d\n", philo->id);
	while (1)
	{
		
	}
	return (NULL);
}
