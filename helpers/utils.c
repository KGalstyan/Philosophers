#include "../philo.h"

int	is_digit(char h)
{
	return(h >= '0' && h <= '9');
}


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


void ft_usleep(size_t milisec)//,t_inputs *input)
{
	size_t start;

	start = get_cur_time();
	while(milisec > get_cur_time() - start)// && (!input->is_dead)) 
		;
}

void print_message(t_philo *philos, char *str)
{
	size_t time;

	pthread_mutex_lock(&philos->write_lock);
	time = get_cur_time() - philos->start_time;
	if(!philos->is_dead)
		printf("%zu %d %s\n", time, philos->id, str);
	pthread_mutex_unlock(&philos->write_lock);
}