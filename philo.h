#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_inputs
{
    size_t philo_num;
    size_t time_d;
    size_t time_e;
    size_t time_s;
    //int last_argum_flag;
    ssize_t eat_num;
} t_inputs;

//helpers//
size_t ft_strlen(char *str);
size_t ft_atoi(const char *nptr);

// input checkers //
int correct_input(int ac, char **av, t_inputs *input);

//utils
int	is_digit(char h);

#endif