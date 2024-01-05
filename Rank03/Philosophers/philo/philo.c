/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 07:50:43 by masoares          #+#    #+#             */
/*   Updated: 2024/01/05 19:44:47 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int *args;
	t_philo *philos;
	t_data data;
	
	if (ac < 5 || ac > 6)
		errors(1);
	args = type_converter(ac, av);
	init_data(&data, args);
	init_threads(&philos, args[0], &data);
	free(args);
	free(philos);
	//finex_threads();
}

int	*type_converter(int ac, char **av)
{
	int *conv_args;
	int i;

	conv_args = (int *)malloc(sizeof(int) * 6);
	if (conv_args == NULL)
		return (NULL);
	i = 0;
	if (ac == 5)
	{
		conv_args[5] = 0;
		while (i < 4)
		{
			conv_args[i] = ft_atoi(av[i + 1]);
			i++;
		}
	}
	else if (ac == 6)
	{
		while (i < 5)
		{
			conv_args[i] = ft_atoi(av[i + 1]);
			i++;
		}
	}
	return (conv_args); 
}

void	*routine(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&((*philo).left_fork));
		pthread_mutex_lock(((*philo).right_fork));
		eating((*philo).data, (*philo).id);
		unlocking_forks(philo);
		sleeping((*philo).data, (*philo).id);
	}
	while (1)
	{
		thinking((*philo).data, (*philo).id);
		locking_forks(philo);
		eating((*philo).data, (*philo).id);
		unlocking_forks(philo);
		sleeping((*philo).data, (*philo).id);
	}
	return(NULL);
}

void locking_forks(t_philo *philo)
{
	long	time;
	
	while (pthread_mutex_lock(&((*philo).left_fork)) 
		|| pthread_mutex_lock((*philo).right_fork))
	{
		pthread_mutex_unlock(&((*philo).left_fork));
		pthread_mutex_unlock((*philo).right_fork);
	}
	gettimeofday(&((*(*philo).data).current_time), NULL);
	time = (((*philo).data)->current_time.tv_sec - 
			((*philo).data)->start_time.tv_sec) * 1000 +
			(((*philo).data)->current_time.tv_usec - 
			((*philo).data)->start_time.tv_usec) / 1000;
	printf("%ld %d has taken a fork\n", time, philo->id);
	printf("%ld %d has taken a fork\n", time, philo->id);
}

void unlocking_forks(t_philo *philo)
{
	pthread_mutex_unlock(&((*philo).left_fork));
	pthread_mutex_unlock(((*philo).right_fork));
}