/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:48:55 by masoares          #+#    #+#             */
/*   Updated: 2023/12/19 11:58:41 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int main(int ac, char **av)
{
	t_data	data;
	int i;
	
	i = 0;
	if (ac == 2)
	{
		//data.pid1 = fork();
		data.altv1 = array_creator_bonus(av[1], "less");
		//if(data.pid1 == 0)
		//{
		//	close(data.fd[0]);
		//	close(data.fd[1]);
		//	if(execve(data.altv1[0], data.altv1, NULL) == -1)
		//		errors_bonus(2, av[2], &data);
		//}
		close(data.fd[0]);
		close(data.fd[1]);
		if(execve("/bin/less", data.altv1, NULL) == -1)
			errors_bonus(2, av[2], &data);
	}
	else if (ac >= 5)
	{
		data.df = open(av[ac - 1], O_WRONLY);
		if (data.df == -1)
			return (perror("Error"), -1);
		data.altv1 = array_creator_bonus(av[1], av[2]);
		data.altv2 = malloc(sizeof(char **) * (ac - 1 - 2 - 1));
		while (i < ac - 1 - 2 - 1)
		{
			(data.altv2)[i] = array_creator2_bonus(av[i + 3]);
			i++;
		}
		if (pipe(data.fd) == -1)
			return (perror("Error"), -2);
		pipex_bonus(&data, av, ac - 1 - 2 - 1);
		free_p1_bonus(&(data.altv1));
		free_p2_bonus(&(data.altv2));
	}
	return (0);
}

void	pipex_bonus(t_data *data, char **av, int com)
{
	int i;
	i = 0;
	data->pid1 = fork();
	if (data->pid1 < 0)
		return ;
	else if(data->pid1 == 0)
	{
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd[0]);
		close(data->fd[1]);
		if(execve(data->altv1[0], data->altv1, NULL) == -1)
			errors_bonus(2, av[2], data);
	}
	while (i < com)
	{
		data->pid2 = fork();
		if (data->pid2 < 0)
			return ;
		else if(data->pid2 == 0)
		{
			dup2(data->fd[0], STDIN_FILENO);
			dup2(data->df, STDOUT_FILENO);
			close(data->fd[0]);
			close(data->fd[1]);
			if(execve((data->altv2)[i][0], (data->altv2)[i], NULL) == -1)
				errors_bonus(2, av[3 + i], data);
		}
	}
	data->pid2 = fork();
	if (data->pid2 < 0)
		return ;
	else if(data->pid2 == 0)
	{
		dup2(data->fd[0], STDIN_FILENO);
		dup2(data->df, STDOUT_FILENO);
		close(data->fd[0]);
		close(data->fd[1]);
		if(execve((data->altv2)[i][0], (data->altv2)[i], NULL) == -1)
			errors_bonus(2, av[3 + i], data);
	}
	close(data->fd[0]);
	close(data->fd[1]);
}

