/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:36:20 by masoares          #+#    #+#             */
/*   Updated: 2023/11/10 20:37:29 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	null_send(int pid);
void	send_char(char c, int pid);

int	main(int ac, char **av)
{
	unsigned char	c;	
	int				pid;
	int				i;
	int				j;

	j = 0;
	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi((const char *)av[1]);
		while (av[2][j] != '\0')
		{
			c = (av[2][j++]);
			if (c <= 176)
				send_char(c, pid);
		}
		i = 0;
		null_send(pid);
	}
}

void	send_char(char c, int pid)
{
	int		i;

	i = 0;
	while (i <= 7)
	{
		if (((c >> (7 - i)) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(500);
	}
}

void	null_send(int pid)
{
	int	i;

	i = 0;
	while (i++ <= 7)
	{
		kill(pid, SIGUSR2);
		usleep(200);
	}
}
