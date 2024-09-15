/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:05:25 by kgalstya          #+#    #+#             */
/*   Updated: 2024/09/12 17:16:13 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	input_checker(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	if (ft_strlen(str) > 10)
		return (1);
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (1);
		i++;
	}
	if (ft_atoi(str) > 2147483647)
		return (1);
	return (0);
}

int	correct_input(int ac, char **av, t_inputs *input)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (input_checker(av[i]))
			return (0);
		i++;
	}
	if (ft_atoi(av[1]) == 0 || ft_atoi(av[1]) > 200)
		return (0);
	if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[2]) < 60)
		return (0);
	input->philo_num = ft_atoi(av[1]);
	input->time_die = ft_atoi(av[2]);
	input->time_eat = ft_atoi(av[3]);
	input->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		input->eat_num = ft_atoi(av[5]);
	else
		input->eat_num = -1;
	return (1);
}
