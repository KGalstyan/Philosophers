#include "philo.h"

void *philo_routine(void *pointer)
{
    t_philo *philos;
    philos = (t_philo *)pointer;

    if(philos->id % 2 == 0)
        ft_usleep(philos->time_eat);
    while(philos->input->is_ready == 0)
        ;
    while(!is_dead(philos))
    {
        eat(philos);
        if(!is_dead(philos))
            _sleep(philos);
        if(!is_dead(philos))
            think(philos);
    }    
    return(NULL);
}

int create_tread(t_inputs *input)
{
    size_t i;

    i = 0;
    while(i < input->philo_num)
    {
        if(pthread_create(&input->philos[i].thread, NULL, philo_routine, &input->philos[i]) == -1)
            return(0);
        i++;
    }
    pthread_mutex_lock(&input->check_lock);
    input->is_ready = 1;
    pthread_mutex_unlock(&input->check_lock);
    while(monitoring(input))
     ;
    i = 0;
    while(i < input->philo_num)
    {
        if(pthread_join(input->philos[i].thread, NULL) == -1)
            return(0);
        i++;
    }
    return(1);
}