/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonard <leonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:53:23 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/08/13 16:08:52 by leonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	has_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
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
	printf("%s", msg);
	return (1);
}

uint64_t	get_time(void)
{
	struct timeval	i;

	gettimeofday(&i, NULL);
	return ((i.tv_sec * 1000) + (i.tv_usec / 1000));
}

void	my_usleep(uint64_t amount, t_rules *rules)
{
	uint64_t	t;

	t = get_time();
	while (!mutex_check_program(rules, 'r'))
	{
		if (get_time() - t >= amount)
			break ;
		usleep(500);
	}
}
