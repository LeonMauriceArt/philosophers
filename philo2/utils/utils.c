/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonard <leonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:53:23 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/08/06 19:43:56 by leonard          ###   ########.fr       */
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

int	error_msg(char *msg)
{
	size_t	i;

	i = 0;
	while (msg[i])
	{
		write(1, &msg[i], 1);
		i++;
	}
	return (1);
}

uint64_t	get_time(void)
{
	struct timeval i;

	gettimeofday(&i, NULL);
	return ((i.tv_sec * 1000) + (i.tv_usec / 1000));
}

void	my_usleep(uint64_t amount, t_rules *rules)
{
	uint64_t	t;

	t = get_time();
	while (rules->program_run)
	{
		if (get_time() - t >= amount)
			break;
		usleep(500);
	}
}