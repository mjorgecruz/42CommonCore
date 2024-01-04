/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 07:50:43 by masoares          #+#    #+#             */
/*   Updated: 2024/01/04 15:32:35 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	int *args;
	int	i;
	t_philo *philos;
	t_data data;
	
	if (ac < 5 || ac > 6)
		errors(1);
	args = (int *)malloc(sizeof(int) * 5);
	if (args == NULL)
		return(-1);
	args = type_converter(ac, av);
	init_data(&data, args);
	init_threads(&philos, args[0]);
	finex_threads();
}

int *type_converter(int ac, char **av)
{
	int conv_args[5];
	int i;

	i = 0;
	if (ac == 5)
	{
		conv_args[4] = 0;
		while (i < 4)
		{
			conv_args[i] = ft_atoi(av[i + 1]);
			i++;
		}
	}
	else if (ac == 6)
	{
		conv_args[5] = 0;
		while (i < 5)
		{
			conv_args[i] = ft_atoi(av[i + 1]);
			i++;
		}
	}
	return (conv_args); 
}

void init_threads(t_philo **philos, int n_of_philos)
{
	int i;
	
	i = 0;
	*philos = malloc(sizeof(t_philo) * n_of_philos);
	if (*philos == NULL)
		return (-2);
	init_structs(philos, n_of_philos);
	
	while (i < n_of_philos)
	{
		pthread_mutex_init(&(philos[i]->left_fork), NULL);
		pthread_create(philos[i], NULL, &philo_routine, NULL);
	}
}

int philo_routine(void *arg)
{
	t_philo *philo;
	philo = (t_philo *) arg;
	
	
}

void	init_structs(t_philo **philos, int n_of_philos)
{
	int	 i;
	
	i = 0;
	while (i < n_of_philos)
	{
		(*philos)[i].id = i + 1;
		if (i == n_of_philos - 1)
			(*philos)[i].next_fork = &((*philos)[0].left_fork); 
		else
			(*philos)[i].next_fork = &((*philos)[i + 1].left_fork);
	}
}

void init_data(t_data *data, int *args)
{
	(*data).t_die = args[1];
	(*data).t_eat = args[2];
	(*data).t_sleep = args[3];
	(*data).n_times_eat = args[4];
	
}