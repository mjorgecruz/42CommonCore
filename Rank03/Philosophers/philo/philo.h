/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 07:52:04 by masoares          #+#    #+#             */
/*   Updated: 2024/01/05 19:49:43 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>

typedef struct s_data
{
	int t_die;
	int t_eat;
	int t_sleep;
	int n_times_eat;
	struct timeval start_time;
	struct timeval current_time;
	struct timeval last_meal;
}       t_data;

typedef struct s_philo
{
	int     id;
	pthread_t philo;
	t_data *data;
	pthread_mutex_t left_fork;
	pthread_mutex_t *right_fork;
}       t_philo;

/* ************************************************************************** */
/*                                 PHILO                                      */
/* ************************************************************************** */
int		*type_converter(int ac, char **av);
void	*routine(void *arg);
void	locking_forks(t_philo *philo);
void	unlocking_forks(t_philo *philo);

/* ************************************************************************** */
/*                              PHILO_UTILS                                   */
/* ************************************************************************** */
int		ft_atoi(char *num);
void	eating(t_data *data, int id);
void	sleeping(t_data *data, int id);
void	thinking(t_data *data, int id);

/* ************************************************************************** */
/*                              PHILO_ERRORS                                  */
/* ************************************************************************** */
void	errors(int code);

/* ************************************************************************** */
/*                               PHILO_INIT                                   */
/* ************************************************************************** */
void	init_data(t_data *data, int *args);
void	init_threads(t_philo **philos, int n_of_philos, t_data *data);
void	init_structs(t_philo **philos, int n_of_philos, t_data *data);

/* ************************************************************************** */
/*                              PHILO_FINEX                                   */
/* ************************************************************************** */

#endif
