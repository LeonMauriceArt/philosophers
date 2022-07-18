/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:23:11 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/07/18 16:24:21 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	display_philo_infos(t_philo *philos)
{
	int i = 0;

	while (philos[i].id != -1)
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