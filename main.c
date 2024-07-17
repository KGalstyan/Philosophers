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
    {
        printf("incorrect args\n");
        return(1);
    }
    if(!memory_allocation(&input))
    {
        system("leaks philo");
        return(1);
    }
    init_data(&input);
    //while()
    if(!create_tread(&input))
    {
        printf("creat thread error\n");
        return(1);
    }
    //printf("all right bro\n");
    memory_clean(&input);
    system("leaks philo");
    return(0);
}
