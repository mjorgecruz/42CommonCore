/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:36:20 by masoares          #+#    #+#             */
/*   Updated: 2023/11/10 20:22:32 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	null_send(int pid);
void	send_char(char c, int pid);

void	handler(int sig, siginfo_t *info, void *c)
{
	(void) info;
	(void) c;
	if (sig == SIGUSR1)
	{
		ft_printf("Message was successfully sent and received");
		exit(EXIT_SUCCESS);
	}
	else if (sig != SIGUSR1)
		ft_printf("Wrong Signal received: %d", sig);
}

int	main(int ac, char **av)
{
	unsigned char		c;	
	int					pid;
	int					i;
	int					j;
	struct sigaction	sig;

	j = 0;
	sig.sa_sigaction = handler;
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		exit(EXIT_FAILURE);
	if (ac == 3)
	{
		i = 0;
		pid = ft_atoi((const char *)av[1]);
		while (av[2][j] != '\0')
		{
			c = (av[2][j++]);
			send_char(c, pid);
		}
		i = 0;
		null_send(pid);
		while (1)
			pause();
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
