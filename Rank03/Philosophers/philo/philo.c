/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 07:50:43 by masoares          #+#    #+#             */
/*   Updated: 2024/01/09 21:37:54 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int		*args;
	t_philo	*philos;
	t_data	data;
	int		i;

	i = 0;
	if (ac < 5 || ac > 6)
		return (errors(1), -1);
	args = type_converter(ac, av);
	if (args == NULL)
		return (-2);
	while (i < 5)
	{
		if (args[i] < -1)
			return (errors(1), free(args), -3);
		i++;
	}
	philos = malloc(sizeof(t_philo) * args[0]);
	if (philos == NULL)
		return (1);
	init_data(&data, args);
	init_threads(philos, args[0], &data);
	finex_threads(philos, &data);
	free(args);
	free(philos);
}

int	*type_converter(int ac, char **av)
{
	int	*conv_args;
	int	i;

	conv_args = (int *)malloc(sizeof(int) * 6);
	if (conv_args == NULL)
		return (NULL);
	i = 0;
	if (ac == 5)
	{
		conv_args[4] = -1;
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
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		thinking(philo, (*philo).id);
	while (get_bool(&(philo->data->data), &philo->data->kill_switch) == false
		&& philo->meals != philo->data->n_times_eat)
	{
		locking_forks(philo);
		eating(philo, (*philo).id);
		unlocking_forks(philo);
		sleeping(philo, (*philo).id);
		if (philo->meals == philo->data->n_times_eat
			|| get_bool(&(philo->data->data),
				&philo->data->kill_switch) == true)
			return (NULL);
		thinking(philo, (*philo).id);
	}
	return (NULL);
}

void	locking_forks(t_philo *philo)
{
	long	time;

	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock((*philo).right_fork);
		pthread_mutex_lock(&((*philo).left_fork));
	}
	else
	{
		pthread_mutex_lock(&((*philo).left_fork));
		pthread_mutex_lock((*philo).right_fork);
	}
	if (get_bool(&(philo->data->data), &philo->data->kill_switch) == false)
	{
		time = get_long(&(philo->data->data), &philo->data->current)
			- get_long(&(philo->data->data), &philo->data->start);
		printf("%ld %d has taken a fork\n", time, philo->id);
		printf("%ld %d has taken a fork\n", time, philo->id);
	}
}

void	unlocking_forks(t_philo *philo)
{
	pthread_mutex_unlock(((*philo).right_fork));
	pthread_mutex_unlock(&((*philo).left_fork));
}
