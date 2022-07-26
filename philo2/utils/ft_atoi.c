/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:36:30 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/06/15 17:03:06 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <limits.h>

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static	int	getsign(const char *str)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			return (sign);
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	long int	result;
	int			i;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		if (str[i + 1] == '+')
			return (0);
		i++;
	}
	if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - 48);
		if ((result * getsign(str)) >= INT_MAX && getsign(str) == -1)
			return (0);
		else if (result > INT_MAX && getsign(str) == 1)
			return (-1);
		i++;
	}
	return (result * getsign(str));
}
