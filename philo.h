#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>


typedef struct s_philo
{
    pthread_t tread;
    int id;
    int eaten_num;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *eat_lock;
    pthread_mutex_t *die_lock;
} t_philo;

typedef struct s_inputs
{
    size_t philo_num;
    size_t time_die;
    size_t time_eat;
    size_t time_sleep;
    ssize_t eat_num;
    size_t start_time;
    int die_status;
    pthread_mutex_t eat_lock;
    pthread_mutex_t die_lock;
    t_philo *philos;
} t_inputs;

//helpers//
size_t ft_strlen(char *str);
size_t ft_atoi(const char *nptr);

// input checkers //
int correct_input(int ac, char **av, t_inputs *input);

//utils
int	is_digit(char h);

void ft_prt(t_inputs *input);
void init_main(t_inputs *input, t_philo *philos);

#endif