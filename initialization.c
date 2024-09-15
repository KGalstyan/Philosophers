/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:05:29 by kgalstya          #+#    #+#             */
/*   Updated: 2024/09/12 22:08:27 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_data_2(t_inputs *input, size_t i)
{
	input->philos[i].id = i + 1;
	input->philos[i].eaten_num = 0;
	input->philos[i].is_dead = 0;
	input->philos[i].philo_num = input->philo_num;
	input->philos[i].time_die = input->time_die;
	input->philos[i].time_eat = input->time_eat;
	input->philos[i].time_sleep = input->time_sleep;
	input->philos[i].eat_num = input->eat_num;
	input->philos[i].start_time = get_cur_time();
	input->philos[i].last_eat_time = get_cur_time();
	input->philos[i].left_fork = &input->forks[i];
}

void	init_data(t_inputs *input)
{
	size_t	i;

	i = 0;
	while (i < input->philo_num)
	{
		init_data_2(input, i);
		if (i == 0)
			input->philos[i].right_fork = &input->forks[input->philo_num - 1];
		else
			input->philos[i].right_fork = &input->forks[i - 1];
		pthread_mutex_init(&input->forks[i], NULL);
		pthread_mutex_init(&input->philos[i].write_lock, NULL);
		pthread_mutex_init(&input->philos[i].eat_nlock, NULL);
		pthread_mutex_init(&input->philos[i].die_lock, NULL);
		pthread_mutex_init(&input->philos[i].time_lock, NULL);
		input->philos[i].input = input;
		i++;
	}
	input->is_ready = 0;
	pthread_mutex_init(&input->check_lock, NULL);
}
