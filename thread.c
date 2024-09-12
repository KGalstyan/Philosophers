/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:05:58 by kgalstya          #+#    #+#             */
/*   Updated: 2024/09/12 17:05:59 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *pointer)
{
	t_philo	*philos;

	philos = (t_philo *)pointer;
    while (1)
	{
		pthread_mutex_lock(&philos->input->check_lock);
		if(philos->input->is_ready == 1)
		{
			pthread_mutex_unlock(&philos->input->check_lock);
			break;
		}
    	pthread_mutex_unlock(&philos->input->check_lock);
	}
	if (philos->id % 2 == 0)
	    ft_usleep(philos->time_eat);
	while (!is_dead(philos))
	{
		eat(philos);
		if (!is_dead(philos))
			_sleep(philos);
		if (!is_dead(philos))
			think(philos);
	}
	return (NULL);
}

int	create_tread(t_inputs *input)
{
	size_t	i;

	i = 0;
	while (i < input->philo_num)
	{
		if (pthread_create(&input->philos[i].thread, NULL, philo_routine,
				&input->philos[i]) == -1)
			return (0);
		i++;
	}
	pthread_mutex_lock(&input->check_lock);
	input->is_ready = 1;
	pthread_mutex_unlock(&input->check_lock);
	while (monitoring(input))
		;
	i = 0;
	while (i < input->philo_num)
	{
		if (pthread_join(input->philos[i].thread, NULL) == -1)
			return (0);
		i++;
	}
	return (1);
}
