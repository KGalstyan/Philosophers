#include "philo.h"

int memory_allocation(t_inputs *input)
{
    input->philos = (t_philo *)malloc(sizeof(t_philo) * input->philo_num);
    if(!input->philos)
    {
        printf("philos malloc error\n");
        return(0);
    }
    input->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * input->philo_num);
    if(!input->forks)
    {
        free(input->philos);
        printf("forks malloc error\n");
        return(0);
    }
    return(1);
}

void memory_clean(t_inputs *input)
{
    size_t i;

    i = 0;
    while(i < input->philo_num)
    {
        pthread_mutex_destroy(&input->forks[i]);
        i++;
    }
    free(input->philos);
    free(input->forks);
}