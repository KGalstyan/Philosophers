#include "philo.h"

int main(int argc, char **argv)
{
    t_inputs input;

    if(argc < 5 || argc > 6)
    {
        printf("wrong number of args\n");
        return(1);
    }
    if(!correct_input(argc, argv, &input))
        return(1);
    printf("all right bro\n");
    return(0);
}