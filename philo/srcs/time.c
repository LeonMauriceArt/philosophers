/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:53:47 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/07/18 19:21:35 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

//personal usleep using small usleeps
void	my_usleep(int time)
{
	int	i;

	i = 0;
	while (i < time)
	{
		usleep(10);
		i += 10;
	}
}

size_t	get_timestamp(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_usec);
}
