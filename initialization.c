#include "philo.h"

void init_data(t_inputs *input)
{
    size_t i;

    i = 0; 
    input->is_dead = 0;
    input->start_time = get_cur_time();

    while(i < input->philo_num)
    {
        input->philos[i].id = i + 1;
        input->philos[i].eaten_num = 0;
        input->philos[i].last_eat_time = get_cur_time();
        input->philos[i].left_fork = &input->forks[i];
        pthread_mutex_init(&input->forks[i], NULL);
        if(i == 0)
            input->philos[i].right_fork = &input->forks[input->philo_num - 1];
        else
            input->philos[i].right_fork = &input->forks[i - 1];
        i++;
    }
}

