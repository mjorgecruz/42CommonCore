/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:37:58 by masoares          #+#    #+#             */
/*   Updated: 2024/01/10 10:12:21 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *num)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	if (num[0] == '-')
		return (-2);
	while (num[i])
	{
		if (num[i] > '9' || num[i] < '0')
			return (-2);
		n = n * 10;
		n = n + (num[i] - '0');
		i++;
	}
	if (n > INT_MAX)
		return (-2);
	return ((int) n);
}

void	eating(t_philo *philo, int id)
{
	long long	time;

	time = get_long(&(philo->data->data), &(philo->data->current))
		- get_long(&(philo->data->data), &(philo->data->start));
	if (get_bool(&(philo->data->data), &(philo->data->kill_switch)) == true)
		return ;
	printf("%lld %d is eating\n", time, id);
	pthread_mutex_lock(&(philo->data->data));
	philo->last_m = get_time();
	pthread_mutex_unlock(&(philo->data->data));
	ft_usleep(philo->data->t_eat);
	philo->meals++;
	if (philo->meals == philo->data->n_times_eat)
		set_bool(&(philo->data->data), true, &(philo->fed));
}

void	sleeping(t_philo *philo, int id)
{
	long long	time;

	time = get_long(&(philo->data->data), &(philo->data->current))
		- get_long(&(philo->data->data), &(philo->data->start));
	if (get_bool(&(philo->data->data), &(philo->data->kill_switch)) == true)
		return ;
	else
		printf("%lld %d is sleeping\n", time, id);
	ft_usleep(philo->data->t_sleep);
}

void	thinking(t_philo *philo, int id)
{
	long long	time;

	time = get_long(&(philo->data->data), &(philo->data->current))
		- get_long(&(philo->data->data), &(philo->data->start));
	if (get_bool(&(philo->data->data), &(philo->data->kill_switch)) == true)
		return ;
	else
		printf("%lld %d is thinking\n", time, id);
}

void	monitoring(t_philo *philos)
{
	int			i;
	long long	time;

	i = 0;
	//set_long(&philos->data->data, get_time(), &(philos->data->current));
	set_int(&(philos->data->data), 0, &(philos->data->feds));
	while (i < philos->data->n_philos)
	{
		philos[i].time_left = get_long(&(philos->data->data),
				&(philos->data->current))
			- get_long(&(philos->data->data), &(philos[i].last_m));
		if (get_bool(&(philos->data->data), &(philos[i].fed)) == true)
		{
			set_int(&(philos->data->data),
				philos->data->feds + 1, &philos->data->feds);
		}
		if (philos[i].time_left >= philos->data->t_die)
		{
			set_bool(&(philos->data->data), true, &(philos->data->kill_switch));
			//set_long(&philos->data->data, get_time(), &(philos->data->current));
			time = get_long(&(philos->data->data), &(philos->data->current))
				- get_long(&(philos->data->data), &(philos->data->start));
			printf("%lld %d died\n", time, (i + 1));
			return ;
		}
		i++;
	}
}

long	get_time(void)
{
	struct timeval	current;
	long			time;

	gettimeofday(&current, NULL);
	time = current.tv_sec * 1000 + current.tv_usec / 1000;
	return (time);
}
