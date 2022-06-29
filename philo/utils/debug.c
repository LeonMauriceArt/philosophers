/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:23:11 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/06/28 16:28:20 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	display_philo_infos(t_philosopher *philos)
{
	int i = 0;
	while (philos[i])
	{
		printf("----------\n");
		printf("Philo ID : %d\n", philos[i].id);
		printf("Has eaten : %d\n", philos[i].has_eaten);
		printf("Is sleeping : %d\n", philos[i].is_sleeping);
		printf("----------\n");
		i++;
	}
	return ;
}