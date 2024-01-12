/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:13:31 by masoares          #+#    #+#             */
/*   Updated: 2024/01/12 15:15:57 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	process(t_philo *philo, t_data *data)
{
	sem_unlink("/philo");
	philo->philex = sem_open("/philo", O_CREAT, 0600, 1);
	philo->data->forks = sem_open("/fork", 0);
	philo->death = sem_open("/death", 0);
	data->start = get_time();
	philo->last_m = get_time();
	data->current = get_time();
	pthread_create(&(philo->philo_routine), NULL, &routine, philo);
	while (get_bool(philo->philex, &philo->data->kill_switch) == false && (get_bool(philo->philex, &philo->fed) == false))
	{
		set_long(philo->philex, get_time(), &(data->current));
		monitoring(philo);
		//if (get_int(philo->philex, &data->feds) == data->n_philos)
		// 	set_bool(philo->philex, true, &(data->kill_switch));
	}
	pthread_join((philo->philo_routine), NULL);
	sem_close(philo->philex);
	return;
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	// while (get_bool(philo->philex, &(philo->data->ok)))
	// ;
	thinking(philo, (*philo).id);
	while (get_bool(philo->philex, &philo->data->kill_switch) == false)
	{
		locking_forks(philo, philo->data->forks);
		eating(philo, (*philo).id);
		unlocking_forks(philo->data->forks);
		sleeping(philo, (*philo).id);
		thinking(philo, (*philo).id);
		if (get_bool(philo->philex, &philo->data->kill_switch) == true || get_bool(philo->philex, &(philo->fed))== true)
		 	return (NULL);
	}
	return (NULL);
}
void	eating(t_philo *philo, int id)
{
	long long	time;

	time = get_long(philo->philex, &(philo->data->current))
		- get_long(philo->philex, &(philo->data->start));
	if (get_bool(philo->philex, &(philo->data->kill_switch)) == true)
		return ;
	sem_wait(philo->death);
	printf("%lld %d is eating\n", time, id);
	sem_post(philo->death);
	sem_wait(philo->philex);
	philo->last_m = get_time();
	sem_post(philo->philex);
	ft_usleep(philo->data->t_eat);
	philo->meals++;
	if (philo->meals == philo->data->n_times_eat)
		set_bool(philo->philex, true, &(philo->fed));
}

void	sleeping(t_philo *philo, int id)
{
	long long	time;

	time = get_long(philo->philex, &(philo->data->current))
		- get_long(philo->philex, &(philo->data->start));
	if (get_bool(philo->philex, &(philo->data->kill_switch)) == true)
		return ;
	sem_wait(philo->death);
	printf("%lld %d is sleeping\n", time, id);
	sem_post(philo->death);
	ft_usleep(philo->data->t_sleep);	
}

void	thinking(t_philo *philo, int id)
{
	long long	time;

	time = get_long(philo->philex, &(philo->data->current))
		- get_long(philo->philex, &(philo->data->start));
	if (get_bool(philo->philex, &(philo->data->kill_switch)) == true)
		return ;
	sem_wait(philo->death);
	printf("%lld %d is thinking\n", time, id);
	sem_post(philo->death);
}

long long	get_time(void)
{
	struct timeval	current;
	long			time;

	gettimeofday(&current, NULL);
	time = current.tv_sec * 1000 + current.tv_usec / 1000;
	return (time);
}

void	monitoring(t_philo *philos)
{
	long long	time;

	//set_long(philos->philex, get_time(), &(philos->data->current));
	philos->time_left = get_long(philos->philex,
				&(philos->data->current))
			- get_long(philos->philex, &(philos->last_m));
	if (philos->fed)
	{
		//sem_wait(philos->death);
		return;
	}
	else if (philos->time_left >= philos->data->t_die)
	{
		set_bool(philos->philex, true, &(philos->data->kill_switch));
		time = get_long(philos->philex, &(philos->data->current))
			- get_long(philos->philex, &(philos->data->start));
		sem_wait(philos->death);
		printf("%lld %d died\n", time, philos->id);
		return ;
	}
	//set_long(philos->philex, get_time(), &(philos->data->current));
}
