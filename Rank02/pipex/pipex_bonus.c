/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:48:55 by masoares          #+#    #+#             */
/*   Updated: 2023/12/18 19:16:23 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int main(int ac, char **av)
{
	t_data	data;

	(void) ac;
	if (ac == 5)
	{
		data.df = open(av[4], O_WRONLY);
		data.altv1 = array_creator_bonus(av[1], av[2]);
		data.altv2 = array_creator2_bonus(av[3]);
		if (pipe(data.fd) == -1)
			return 1;
		pipex_bonus(&data);
		return (ft_free_pipex1_bonus(&(data.altv1)), ft_free_pipex2_bonus(&(data.altv2)), 0);
	}
	else 
	{
		return(write(STDERR_FILENO, "deu coco", 8));
	}
}
void	pipex_bonus(t_data *data)
{
	data->pid1 = fork();
	if (data->pid1 < 0)
		return ;
	else if(data->pid1 == 0)
	{
		dup2(data->fd[1], STDOUT_FILENO);
		close(data->fd[0]);
		close(data->fd[1]);
		execve(data->altv1[0], data->altv1, NULL);
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
		execve(data->altv2[0], data->altv2, NULL);
	}
	close(data->fd[0]);
	close(data->fd[1]);
	waitpid(data->pid1, NULL, 0);
	waitpid(data->pid2, NULL, 0);
}

