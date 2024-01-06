/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:37:58 by masoares          #+#    #+#             */
/*   Updated: 2024/01/06 15:38:20 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *num)
{
	int i;
	long n;
	
	i = 0;
	n = 0;
	if (num[0] == '-')
		errors(2);
	while (num[i])
	{
		if (num[i] > '9' || num[i] < '0')
			errors(3);
		n = n * 10;
		n = n + (num[i] - '0');
		i++;
	}
	if (n > INT_MAX)
		errors(4);
	return ((int) n);
}

void	eating(t_data *data,  int id)
{
	long time;

	time = ((*data).current_time.tv_sec - (*data).start_time.tv_sec)*1000 +
			((*data).current_time.tv_usec - (*data).start_time.tv_usec)/1000;
	printf("%ld %d is eating\n", time, id);
	usleep(data->t_eat * 1000);
}

void	sleeping(t_data *data, int id)
{
	long time;

	time = ((*data).current_time.tv_sec - (*data).start_time.tv_sec)*1000 +
			((*data).current_time.tv_usec - (*data).start_time.tv_usec)/1000;
	printf("%ld %d is sleeping\n", time, id);
	usleep(data->t_sleep * 1000);
}

void	thinking(t_data *data, int id)
{
	long time;

	time = ((*data).current_time.tv_sec - (*data).start_time.tv_sec)*1000 +
			((*data).current_time.tv_usec - (*data).start_time.tv_usec)/1000;
	printf("%ld %d is thinking\n", time, id);
}

void	*routine2(void *arg)
{
	t_joker *joker;
	int		i;
	
	joker = (t_joker *) arg;
	while(1)
	{
		i = 0;
		while (i < (joker->data)->n_philos)
		{
			if((joker->data->current_time - joker->philos)[i]->last_meal 
			{
				i = kill;
				break;
			}
			
			i++;
		}
	}

}
