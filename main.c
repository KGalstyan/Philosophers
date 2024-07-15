#include "philo.h"

int main(int argc, char **argv)
{
    t_inputs input;
    t_philo philos;

    if(argc < 5 || argc > 6)
    {
        printf("wrong number of args\n");
        return(1);
    }
    if(!correct_input(argc, argv, &input))
    {
        printf("incorrect args\n");
        return(1);
    }
    init_main(&input, &philos);
    ft_prt(&input);
    printf("all right bro\n");
    return(0);
}