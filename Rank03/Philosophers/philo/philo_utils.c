/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:37:58 by masoares          #+#    #+#             */
/*   Updated: 2024/01/08 22:44:43 by masoares         ###   ########.fr       */
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
		return(-2);
	while (num[i])
	{
		if (num[i] > '9' || num[i] < '0')
			return(-2);
		n = n * 10;
		n = n + (num[i] - '0');
		i++;
	}
	if (n > INT_MAX)
		return(-2);
	return ((int) n);
}

void	eating(t_philo *philo,  int id)
{
	long time;

	time = philo->data->current - philo->data->start;
	if (philo->data->kill_switch == true)
		return ;
	printf("%ld %d is eating\n", time, id);
	philo->last_m = get_time();
	usleep(philo->data->t_eat * 1000);
	philo->meals++;
	if (philo->meals == philo->data->n_times_eat)
		philo->fed = true;
}

void	sleeping(t_philo *philo, int id)
{
	long time;

	time = philo->data->current - philo->data->start;
	if (philo->data->kill_switch == true)
		return ;
	else	
		printf("%ld %d is sleeping\n", time, id);
	usleep(philo->data->t_sleep * 1000);
}

void	thinking(t_philo *philo, int id)
{
	long time;

	time = philo->data->current - philo->data->start;
	if (philo->data->kill_switch == true)
		return ;
	else
		printf("%ld %d is thinking\n", time, id);
}

void	monitoring(t_philo *philos)
{
	int		i;
	long	time;
	
	i = 0;
	philos->data->feds = 0;
	while (i < philos->data->n_philos)
	{
		philos[i].time_left = time_left_calc(philos[i], philos[i].data);
		if (philos[i].time_left > philos->data->t_die)
		{
			philos->data->kill_switch = true;
			time = philos->data->current - philos->data->start;
			printf("%ld %d died\n", time, (i + 1));
			break ;
		}
		if (philos[i].fed == true)
		 	philos->data->feds++;
		i++;
	}
}

int time_left_calc(t_philo philos, t_data *data)
{
	int time_left;

	time_left = data->current - philos.last_m;
	return (time_left);
}

long	get_time()
{
	struct timeval current;
	long	time;
	gettimeofday(&current, NULL);
	time = current.tv_sec * 1000 + current.tv_usec / 1000;

	return (time);
	
}