/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:58:21 by masoares          #+#    #+#             */
/*   Updated: 2023/11/29 14:49:50 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_errors(int ac, char **num_list)
{
	int	error;

	error = 0;
	error = check_strings(ac, num_list);
	if (error != 0)
		return (-1);
	error = check_max_min(ac, num_list);
	if (error != 0)
		return (-2);
	error = check_dups(ac, num_list);
	if (error != 0)
		return (-3);
	return (0);
}

int	check_strings(int ac, char **num_list)
{
	int		i;
	int		j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (num_list[i][j] == '-' || num_list[i][j] == '+')
			j++;
		while (num_list[i][j] != '\0')
		{
			if (ft_isdigit(num_list[i][j]) == 0)
			{
				write(STDERR_FILENO, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_max_min(int ac, char **num_list)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (i < ac)
	{
		num = ft_atol(num_list[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (write(STDERR_FILENO, "Error\n", 6), 1);
		i++;
	}
	return (0);
}

int	check_dups(int ac, char **num_list)
{
	long	num;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < ac)
	{
		num = ft_atoi(num_list[i]);
		j = i + 1;
		while (j < ac)
		{
			if (num == ft_atoi(num_list[j]))
			{
				write(STDERR_FILENO, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
