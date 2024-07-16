#include "philo.h"

void *philo_routine(void *pointer)
{
    (void)pointer;
    printf("you are in thread\n");
    return(NULL);
}

int create_tread(t_inputs *input)
{
    size_t i;

    i = 0;
    while(i < input->philo_num)
    {
        if(pthread_create(&input->philos[i].thread, NULL, philo_routine, NULL) == -1)
            return(0);
        if(pthread_join(input->philos[i].thread, NULL) == -1)
            return(0);
        i++;
    }
    return(1);
}