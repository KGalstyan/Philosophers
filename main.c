/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:05:33 by kgalstya          #+#    #+#             */
/*   Updated: 2024/09/12 17:05:34 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    if(!create_tread(&input))
    {
        printf("creat thread error\n");
        memory_clean(&input);
        system("leaks philo");
        return(1);
    }
    memory_clean(&input);
    system("leaks philo");
    return(0);
}
