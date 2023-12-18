/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:48:55 by masoares          #+#    #+#             */
/*   Updated: 2023/12/18 18:49:17 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int main(int ac, char **av)
// {
// 	pid_t pid1;
// 	pid_t pid2;
// 	int fd[2];
// 	int	df;
// 	char **altv1;
// 	char **altv2;
// 	(void) ac;

// 	df = open(av[4], O_WRONLY);
// 	altv1 = array_creator(av[1], av[2]);
// 	altv2 = array_creator2(av[3]);
// 	if (altv1 == NULL)
// 		return 1;
// 	if (pipe(fd) == -1)
// 		return 1;
// 	pid1 = fork();
// 	if (pid1 < 0)
// 		return 2;
// 	else if(pid1 == 0)
// 	{
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execve(altv1[0], altv1, NULL);
// 	}
// 	pid2 = fork();
// 	if (pid2 < 0)
// 		return 3;
// 	else if(pid2 == 0)
// 	{
// 		dup2(fd[0], STDIN_FILENO);
// 		dup2(df, STDOUT_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execve(altv2[0], altv2, NULL);
// 	}
// 	close(fd[0]);
// 	close(fd[1]);
// 	ft_free_pipex1(altv1);
// 	ft_free_pipex2(altv2);
// 	free(altv1);
// 	free(altv2);
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	return 0;
// }

int main(int ac, char **av)
{
	t_data	data;

	(void) ac;
	if (ac == 5)
	{
		data.df = open(av[4], O_WRONLY);
		data.altv1 = array_creator(av[1], av[2]);
		data.altv2 = array_creator2(av[3]);
		if (pipe(data.fd) == -1)
			return 1;
		pipex(&data);
		return (ft_free_pipex1(&(data.altv1)), ft_free_pipex2(&(data.altv2)), 0);
	}
	else 
	{
		return(write(STDERR_FILENO, "deu coco", 8));
	}
}
void	pipex(t_data *data)
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

