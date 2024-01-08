/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:46:18 by masoares          #+#    #+#             */
/*   Updated: 2024/01/08 22:57:09 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, int *args)
{
	(*data).n_philos = args[0];
	(*data).t_die = args[1];
	(*data).t_eat = args[2];
	(*data).t_sleep = args[3];
	(*data).n_times_eat = args[4];
	(*data).kill_switch = false;
	(*data).feds = 0;
}

void	init_threads(t_philo *philos, int n_of_philos, t_data *data)
{
	int i;
	
	i = 0;
	init_structs(philos, n_of_philos, data);
	data->start = get_time();
	data->current = get_time();
	while (i < n_of_philos)
	{
		philos[i].last_m = get_time();
		pthread_mutex_init(&philos[i].left_fork, NULL);
		pthread_create(&philos[i].philo, NULL, &routine, &philos[i]);
		i++;
	}
	while (philos->data->kill_switch == false && data->feds != data->n_times_eat)
	{
		data->current = get_time();
		monitoring(philos);
	}
}

void	init_structs(t_philo *philos, int n_of_philos, t_data *data)
{
	int	 i;
	
	i = 0;
	while (i < n_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].data = data;
		philos[i].meals = 0;
		philos[i].fed = false;
		philos[i].data->kill_switch = false;
		if (i == n_of_philos - 1)
			philos[i].right_fork = &philos[0].left_fork; 
		else
			philos[i].right_fork = &philos[i + 1].left_fork;
		i++;
		
	}
}
