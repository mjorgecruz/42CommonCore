/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:46:18 by masoares          #+#    #+#             */
/*   Updated: 2024/01/06 15:29:09 by masoares         ###   ########.fr       */
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
}

void	init_threads(t_philo **philos, int n_of_philos, t_data *data)
{
	int i;
	t_joker joker;
	
	i = 0;
	*philos = malloc(sizeof(t_philo) * n_of_philos);
	if (*philos == NULL)
		return ;
	init_structs(philos, n_of_philos, data);
	init_joker(&joker, data, philos, n_of_philos);
	gettimeofday(&((*data).start_time), NULL);
	pthread_create(&(joker.joker), NULL, &routine2, &joker);
	while (i < n_of_philos)
	{
		pthread_mutex_init(&((*philos)[i].left_fork), NULL);
		pthread_create(&((*philos)[i].philo), NULL, &routine, &((*philos)[i]));
		i++;
	}
	while (data->kill_switch == false)
	{
		gettimeofday(&((*data).current_time), NULL);
	}
	// i = 0;
	// while (i < n_of_philos)
	// {
	// 	pthread_mutex_destroy(&((*philos)[i].left_fork));
	// 	pthread_join(((*philos)[i].philo), NULL);
	// 	i++;
	// }
	/* 
	. Criar nova thread para ler o tempo atual e comparar
	com o tempo da ultima refeicao de todos os filosofos
	 */
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

void init_joker(t_joker *joker, t_data *data, t_philo **philos, int n_philos)
{
	int	i;
	
	i = 0;
	joker->data = data;
	joker->philos = philos;
	joker->time_left = malloc(sizeof(int) *n_philos);
	if ((joker->time_left) == NULL)
		return ;
	while (i < n_philos)
	{
		(joker->time_left)[i] = 0;
		i++;
	}
	joker->kill_switch = false;
}
