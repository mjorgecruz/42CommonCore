/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_finex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:46:24 by masoares          #+#    #+#             */
/*   Updated: 2024/01/08 21:48:14 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void finex_threads(t_philo *philos, t_data *data)
{
	int i;

	i = 0;
	while (i < (data->n_philos))
	{
		pthread_join(philos[i].philo, NULL);
		pthread_mutex_destroy(&(philos[i].left_fork));
		i++;
	}
}