#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>


typedef struct s_philo
{
    size_t philo_num;
    size_t time_die;
    size_t time_eat;
    size_t time_sleep;
    ssize_t eat_num;

    pthread_t thread;
    int id;
    int eaten_num;
    size_t last_eat_time;
    size_t start_time;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    int is_dead;
    pthread_mutex_t write_lock;
    pthread_mutex_t eat_nlock;
    pthread_mutex_t die_lock;
} t_philo;

typedef struct s_inputs
{
    size_t philo_num;
    size_t time_die;
    size_t time_eat;
    size_t time_sleep;
    ssize_t eat_num;
    pthread_mutex_t *forks;
    t_philo *philos;
} t_inputs;

//helpers//
size_t ft_strlen(char *str);
size_t ft_atoi(const char *nptr);

// utils //
int	is_digit(char h);
void ft_prt(t_inputs *input);

size_t get_cur_time(void);
void ft_usleep(size_t milisec);//, t_inputs *input);
void print_message(t_philo *philos, char *str);

// input checkers //
int correct_input(int ac, char **av, t_inputs *input);

// allocation //
int memory_allocation(t_inputs *input);
void memory_clean(t_inputs *input);

// initialization //
void init_data(t_inputs *input);

// threads //
int create_tread(t_inputs *input);

// actions //
void _sleep(t_philo *philos);
void think(t_philo *philos);
void eat(t_philo *philos);
int is_dead(t_philo *philos);


#endif