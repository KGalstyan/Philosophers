#include "philo.h"

void die_all(t_inputs *input)
{
    size_t n;

    n = 0;
    while(n < input->philo_num)
    {
        pthread_mutex_lock(&input->philos[n].die_lock);
        input->philos[n].is_dead = 1;
        pthread_mutex_unlock(&input->philos[n].die_lock);
        n++;
    }
}

int all_eaten(t_inputs *input)
{
    size_t n;

    n = 0;
    while(n < input->philo_num)
    {
        if(input->philos[n].eaten_num == input->eat_num)
            return(1);
        n++;
    }
    return(0);
}

int monitoring(t_inputs *input)
{
    size_t i;

    i = 0;
    while(i < input->philo_num)
    {
        pthread_mutex_lock(&input->philos[i].time_lock);
        if(get_cur_time() - input->philos[i].last_eat_time >= input->time_die)
        {
            die_all(input);
            print_message(&input->philos[i], "died");
            pthread_mutex_unlock(&input->philos[i].time_lock);
            return(0);
        }
        pthread_mutex_lock(&input->philos[i].eat_nlock);
        if(all_eaten(input))
        {
            die_all(input);
            pthread_mutex_unlock(&input->philos[i].eat_nlock);
            pthread_mutex_unlock(&input->philos[i].time_lock);
            return(0);
        }
        pthread_mutex_unlock(&input->philos[i].eat_nlock);
        pthread_mutex_unlock(&input->philos[i].time_lock);
        i++;
    }
    return(1);
}
