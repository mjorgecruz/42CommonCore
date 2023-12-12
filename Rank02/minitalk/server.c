/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:13:38 by masoares          #+#    #+#             */
/*   Updated: 2023/11/10 20:16:16 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *c)
{
	unsigned static char	rec = 0;
	static int				i = 0;

	(void) c;
	(void) info;
	if (sig == SIGUSR1)
		rec = rec | 1;
	else if (sig == SIGUSR2)
		rec = rec | 0;
	i++;
	if (i <= 7)
		rec <<= 1;
	if (i == 8)
	{
		write(1, &rec, 1);
		rec = 0;
		i = 0;
	}
	else if (sig != SIGUSR1 && sig != SIGUSR2)
		ft_printf("Wrong Signal received: %d", sig);
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	sig.sa_sigaction = handler;
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sig, NULL) == -1)
		exit(EXIT_FAILURE);
	pid = getpid();
	if (pid == -1)
		return (1);
	ft_printf("%d\n", pid);
	while (1)
	{
		pause();
	}
}
