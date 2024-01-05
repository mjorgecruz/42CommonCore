/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 07:50:43 by masoares          #+#    #+#             */
/*   Updated: 2024/01/05 00:25:01 by masoares         ###   ########.fr       */
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

void	*routine(void *arg)
{
	t_philo *philo;
	philo = (t_philo *) arg;	
	printf("%d", philo->id);
	sleep(1);
	return(NULL);
}

