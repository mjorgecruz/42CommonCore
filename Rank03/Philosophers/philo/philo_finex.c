/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_finex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:46:24 by masoares          #+#    #+#             */
/*   Updated: 2024/01/09 22:05:41 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	finex_threads(t_philo *philos, t_data *data)
{
	int	i;
	if (data->n_philos >= 2)
	{
		i = 0;
		while (i < (data->n_philos))
		{
			pthread_join(philos[i].philo, NULL);
			i++;
		}
		i = 0;
		while (i < (data->n_philos))
		{
			pthread_mutex_destroy(&(philos[i].left_fork));
			i++;
		}
	}
	pthread_mutex_destroy(&(data->data));
}
