/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonard <leonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:31:59 by lmaurin-          #+#    #+#             */
/*   Updated: 2022/08/07 18:47:13 by leonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

//check if args are valid args
int	check_args(int ac, char *av[])
{
	if (has_alpha(av[1]) == true)
		return (error_msg("Bad argument\n"));
	if (has_alpha(av[2]) == true)
		return (error_msg("Bad argument\n"));
	if (has_alpha(av[3]) == true)
		return (error_msg("Bad argument\n"));
	if (has_alpha(av[4]) == true)
		return (error_msg("Bad argument\n"));
	if (ac == 6)
		if (has_alpha(av[5]) == true)
			return (error_msg("Bad argument\n"));
	return (0);
}

//check if after parsing the args are still valid
int	check_init(t_rules *rules)
{
	if (rules->philo_nb == 0 || rules->philo_nb > INT_MAX)
		return (error_msg("Number of philosophers must be greater then 0\n"));
	if (rules->time_to_die == 0 || rules->time_to_die > INT_MAX)
		return (error_msg("Time to die must be greater then 0\n"));
	if (rules->time_to_eat == 0 || rules->time_to_eat > INT_MAX)
		return (error_msg("Time to eat must be greater then 0\n"));
	if (rules->time_to_sleep == 0 || rules->time_to_sleep > INT_MAX)
		return (error_msg("Time to sleep must be greater then 0\n"));
	if (rules->optional_arg == true && rules->philo_nb_eat == 0)
		return (error_msg("Times philosophers eats must be greater then 0\n"));
	if (rules->optional_arg == true && !rules->philo_nb_eat)
		return (error_msg("Times philos eats must be inferior of INT_MAX\n"));
	return (0);
}

//parse the args and assign to t_args struct
void	args_init(int ac, char *av[], t_rules *rules)
{
	rules->philo_nb = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		rules->optional_arg = true;
		rules->philo_nb_eat = ft_atoi(av[5]);
	}
	else
	{
		rules->optional_arg = false;
		rules->philo_nb_eat = -1;
	}
	rules->correct_parsing = true;
	return ;
}

//main function for parsing
t_rules	parsing(int ac, char *av[])
{
	t_rules	rules;

	if (check_args(ac, av) == 1)
	{
		rules.correct_parsing = false;
		return (rules);
	}
	args_init(ac, av, &rules);
	if (check_init(&rules))
		rules.correct_parsing = false;
	return (rules);
}
