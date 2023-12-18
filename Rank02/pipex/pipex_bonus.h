/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:24:12 by masoares          #+#    #+#             */
/*   Updated: 2023/12/18 18:53:50 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "./libft/libft.h"

typedef struct s_data
{
        pid_t pid1;
	pid_t pid2;
	int fd[2];
	int	df;
	char **altv1;
	char **altv2;
}       t_data;

void	pipex_bonus(t_data *data);
char **array_creator_bonus(char *file, char *str);
char **array_creator2_bonus(char *str);
void	ft_free_pipex1_bonus(char ***altv);
void	ft_free_pipex2_bonus(char ***altv);

