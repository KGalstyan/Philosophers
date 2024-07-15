#include "philo.h"

void init_philos(t_inputs *input, t_philo *philos)
{
    size_t i = 0;
    //input->philos = (t_philo *)malloc(sizeof(t_philo) * input->philo_num);
    input->die_status = 0;
    pthread_mutex_init(&input->eat_lock, NULL);
    pthread_mutex_init(&input->die_lock, NULL);
    while(i < input->philo_num)
    {
        philos->id = i + 1;
        philos->eaten_num = 0;
        pthread_mutex_init(philos->eat_lock, NULL);
        pthread_mutex_init(philos->die_lock, NULL);
        pthread_mutex_init(philos->left_fork, NULL);
        pthread_mutex_init(philos->right_fork, NULL);
    }
}

// void init_forks(t_inputs *input, t_philo *philos)
// {
//     int i;

//     i = 0;
//     while(i < input->philo_num)
//     {
//         pthread_mutex_init();
//     }
// }

void init_main(t_inputs *input, t_philo *philos)
{
    // init_forks(input, philos);
    init_philos(input, philos);
}