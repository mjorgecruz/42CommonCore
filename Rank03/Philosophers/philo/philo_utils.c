/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:37:58 by masoares          #+#    #+#             */
/*   Updated: 2024/01/04 23:44:34 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(char *num)
{
	int i;
	long n;
	
	i = 0;
	n = 0;
	if (num[0] == '-')
		errors(2);
	while (num[i])
	{
		if (num[i] > '9' || num[i] < '0')
			errors(3);
		n = n * 10;
		n = n + (num[i] - '0');
		i++;
	}
	if (n > INT_MAX)
		errors(4);
	return ((int) n);
}