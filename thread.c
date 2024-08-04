#include "philo.h"

void *philo_routine(void *pointer)
{
    t_philo *philos;
    philos = (t_philo *)pointer;

    if(philos->id % 2 == 0)
        usleep(philos->time_eat);
    while(!is_dead(philos))
    {
        eat(philos);
        _sleep(philos);
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