#include "philo.h"

int input_checker(char *str)
{
    int i;

    i = 0;
    if(!str[i])
    {
        printf("nothing in arg value !?\n");
        return(1);
    }
    if(ft_strlen(str) > 10)
    {
        printf("Value is incorrect\n");
        return(1);
    }
    while(str[i])
    {
        if(!is_digit(str[i]))
        {
            printf("incorrect argument in include\n");
            return(1);
        }
        i++;
    }
    if(ft_atoi(str) > 2147483647)
    {
        printf("Maxerror\n");
        return(1);
    }
    return(0);
}

int correct_input(int ac, char **av, t_inputs *input)
{
    int i;

    i = 1;
    while(i < ac)
    {
        if(input_checker(av[i]))
            return(0);
        i++;
    }
    if(ft_atoi(av[1]) == 0 || ft_atoi(av[1]) > 200)
    {
        printf("1st arg is incorrect\n");
        return(0);
    }
    if(ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[2]) < 60)
    {
        printf("2 or 3 or 4 is wrong\n");
        return(0);
    }
    input->philo_num = ft_atoi(av[1]);
    input->time_die = ft_atoi(av[2]);
    input->time_eat = ft_atoi(av[3]);
    input->time_sleep = ft_atoi(av[4]);
    if(ac == 6)
        input->eat_num = ft_atoi(av[5]);
    else
        input->eat_num = -1;
    printf("philo_num = %zu\n", input->philo_num);
    printf("time_d = %zu\n", input->time_die);
    printf("time_e = %zu\n", input->time_eat);
    printf("time_s = %zu\n", input->time_sleep);
    printf("eat_num = %jd\n", input->eat_num);
    return(1);
}
