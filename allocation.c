/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:05:20 by kgalstya          #+#    #+#             */
/*   Updated: 2024/09/12 17:05:21 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	memory_allocation(t_inputs *input)
{
	input->philos = (t_philo *)malloc(sizeof(t_philo) * input->philo_num);
	if (!input->philos)
	{
		printf("philos malloc error\n");
		return (0);
	}
	input->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* input->philo_num);
	if (!input->forks)
	{
		free(input->philos);
		printf("forks malloc error\n");
		return (0);
	}
	return (1);
}

void	memory_clean(t_inputs *input)
{
	size_t	i;

	i = 0;
	pthread_mutex_destroy(&input->check_lock);
	while (i < input->philo_num)
	{
		pthread_mutex_destroy(&input->forks[i]);
		pthread_mutex_destroy(&input->philos[i].eat_nlock);
		pthread_mutex_destroy(&input->philos[i].write_lock);
		pthread_mutex_destroy(&input->philos[i].die_lock);
		pthread_mutex_destroy(&input->philos[i].time_lock);
		i++;
	}
	free(input->philos);
	free(input->forks);
}
