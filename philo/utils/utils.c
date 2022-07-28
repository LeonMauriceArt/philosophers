/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:53:23 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/07/28 18:07:14 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	has_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return (true);
	}
	return (false);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	error_msg(char *msg)
{
	write(1, msg, ft_strlen(msg));
	return (1);
}

void	my_usleep(uint64_t amount)
{
	uint64_t		elapsed;
	struct timeval	start;

	elapsed = 0;
	start = (struct timeval){0};
	while (elapsed < amount)
	{
		usleep(50);
		elapsed = get_timestamp(start);
	}
	return ;
}

uint64_t	get_timestamp(struct timeval start_time)
{
	struct timeval		current_time;
	uint64_t			time_i;
	uint64_t			time_j;

	gettimeofday(&current_time, NULL);
	time_i = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	time_j = start_time.tv_sec * 1000 + start_time.tv_usec / 1000;
	return (time_i - time_j);
}
