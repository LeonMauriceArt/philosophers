/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:31:59 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/06/15 19:32:48 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_args(int ac, char *av[])
{
	if (has_alpha(av[1]) == true)
		error_msg("Bad argument\n");
	if (has_alpha(av[2]) == true)
		error_msg("Bad argument\n");
	if (has_alpha(av[3]) == true)
		error_msg("Bad argument\n");
	if (has_alpha(av[4]) == true)
		error_msg("Bad argument\n");
	if (ac == 6)
		if (has_alpha(av[5]) == true)
			error_msg("Bad argument\n");
	return (0);
}

int	check_init(t_args *args)
{
	if (args->philo_nb == 0 || args->philo_nb > INT_MAX)
		error_msg("Number of philosophers must be greater then 0\n");
	if (args->time_to_die == 0 || args->time_to_die > INT_MAX)
		error_msg("Time to die must be greater then 0\n");
	if (args->time_to_eat == 0 || args->time_to_eat > INT_MAX)
		error_msg("Time to eat must be greater then 0\n");
	if (args->time_to_sleep == 0 || args->time_to_sleep > INT_MAX)
		error_msg("Time to sleep must be greater then 0\n");
	if (args->optional_arg == true && args->philo_nb_eat == 0)
		error_msg("Times philosophers eats must be greater then 0\n");
	if (args->optional_arg == true && args->philo_nb_eat == -1)
		error_msg("Times philosophers eats must be inferior of INT_MAX\n");
	return (0);
}

void	args_init(int ac, char *av[], t_args *args)
{
	args->philo_nb = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		args->optional_arg = true;
		args->philo_nb_eat = ft_atoi(av[5]);
	}
	else
	{
		args->optional_arg = false;
		args->philo_nb_eat = -1;
	}
	return ;
}

t_args	parsing(int ac, char *av[])
{
	t_args	args;

	check_args(ac, av);
	args_init(ac, av, &args);
	check_init(&args);
	return (args);
}
