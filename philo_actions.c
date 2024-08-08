#include "philo.h"

void _sleep(t_philo *philos)
{
    print_message(philos, "is sleeping");
    ft_usleep(philos->time_sleep); 
}

void think(t_philo *philos)
{
    print_message(philos, "is thinking");
}

void eat(t_philo *philos)
{
    pthread_mutex_lock(philos->left_fork);
    // if(is_dead(philos))
    // {
    //     pthread_mutex_unlock(philos->left_fork);
    //     return ;
    // }
    print_message(philos, "has taken a fork");
    if(philos->philo_num == 1)
    {
        ft_usleep(philos->time_die);
        philos->is_dead = 1;
        //pthread_mutex_unlock(philos->left_fork);
        return ;
    }
    pthread_mutex_lock(philos->right_fork);
    //if(is_dead(philos))
    // {
    //     pthread_mutex_unlock(philos->left_fork);
    //     pthread_mutex_unlock(philos->right_fork);
    //     return ;
    // }
    print_message(philos, "has taken a fork");
    pthread_mutex_lock(&philos->eat_nlock);
    // if(is_dead(philos))
    // {
    //     pthread_mutex_unlock(philos->left_fork);
    //     pthread_mutex_unlock(philos->right_fork);
    //     pthread_mutex_unlock(&philos->eat_nlock);
    //     return ;
    // }
    print_message(philos, "is eating");
    philos->eaten_num++;
    pthread_mutex_unlock(&philos->eat_nlock);
    ft_usleep(philos->time_eat);
    pthread_mutex_lock(&philos->time_lock);
    philos->last_eat_time = get_cur_time();
    pthread_mutex_unlock(&philos->time_lock);
    pthread_mutex_unlock(philos->left_fork);
    pthread_mutex_unlock(philos->right_fork);
}

int is_dead(t_philo *philos)
{
    pthread_mutex_lock(&philos->die_lock);
    if(philos->is_dead)
    {
        pthread_mutex_unlock(&philos->die_lock);
        return(1);
    }
    pthread_mutex_unlock(&philos->die_lock);
    return(0);
}