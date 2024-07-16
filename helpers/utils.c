#include "../philo.h"

int	is_digit(char h)
{
	return(h >= '0' && h <= '9');
}

// void ft_thistime(size_t time, t_inputs *input)
// {
// 	size_t moment = time - input->start_time;
// 	printf("my time is %zu\n", moment);
// }

size_t get_cur_time(void)
{
    struct timeval currtime;

    if(gettimeofday(&currtime, NULL) == -1)
	{
		printf("get time erreo\n");
		return(0);
	}
	return(currtime.tv_sec * 1000 + currtime.tv_usec / 1000);
}

// void ft_prt(t_inputs *input)
// {
// 	int i = 0;
// 	size_t time  = 0;
// 	input->start_time = ft_time(input->start_time);
// 	while(i < 25)
// 	{
// 		time = ft_time(time);
// 		ft_thistime(time, input);
// 		usleep(1000);
// 		i++;
// 	}
// }

void ft_usleep(size_t milisec, t_inputs *input)
{
	size_t start;

	start = get_cur_time();
	while(milisec > get_cur_time() - start && (!input->is_dead))
		;
}