/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:46:18 by masoares          #+#    #+#             */
/*   Updated: 2024/01/05 14:46:08 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, int *args)
{
	(*data).t_die = args[1];
	(*data).t_eat = args[2];
	(*data).t_sleep = args[3];
	(*data).n_times_eat = args[4];
}

void	init_threads(t_philo **philos, int n_of_philos, t_data *data)
{
	int i;
	
	i = 0;
	*philos = malloc(sizeof(t_philo) * n_of_philos);
	if (*philos == NULL)
		return ;
	init_structs(philos, n_of_philos, data);
	
	gettimeofday(&((*data).start_time), NULL);
	while (i < n_of_philos)
	{
		pthread_mutex_init(&((*philos)[i].left_fork), NULL);
		pthread_create(&((*philos)[i].philo), NULL, &routine, &((*philos)[i]));
		i++;
	}
	i = 0;
	while (i < n_of_philos)
	{
		pthread_mutex_destroy(&((*philos)[i].left_fork));
		pthread_join(((*philos)[i].philo), NULL);
		i++;
	}
}

void	init_structs(t_philo **philos, int n_of_philos, t_data *data)
{
	int	 i;
	
	i = 0;
	while (i < n_of_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].data = data;
		if (i == n_of_philos - 1)
			(*philos)[i].right_fork = &((*philos)[0].left_fork); 
		else
			(*philos)[i].right_fork = &((*philos)[i + 1].left_fork);
		i++;
	}
}
