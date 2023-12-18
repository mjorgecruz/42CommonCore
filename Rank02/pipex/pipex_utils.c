/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:42:32 by masoares          #+#    #+#             */
/*   Updated: 2023/12/18 18:43:44 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **array_creator(char *file, char *str)
{
	char	**array;
	char	**final_array;
	int		size;
	int		i;

	i = 1;
	size = 0;
	array = ft_split(str, ' ');
	while (array[size] != NULL)
		size++;
	final_array = (char **) malloc(sizeof(char *) * (size + 2));
	if (final_array == NULL)
		return (NULL);
	final_array[0] = ft_strjoin("/bin/", array[0]);
	free (array[0]);
	while (i < size)
	{
		final_array[i] = array[i]; 
		i++;
	}
	final_array[size] = file;
	final_array[size + 1] = NULL; 
	free(array);
	return (final_array);
}

char **array_creator2(char *str)
{
	char	**array;
	char	**final_array;
	int		size;
	int		i;

	i = 1;
	size = 0;
	array = ft_split(str, ' ');
	while (array[size] != NULL)
		size++;
	final_array = (char **) malloc(sizeof(char *) * (size + 1));
	if (final_array == NULL)
		return (NULL);
	final_array[0] = ft_strjoin("/bin/", array[0]);
	free (array[0]);
	while (i < size)
	{
		final_array[i] = array[i]; 
		i++;
	}
	final_array[size] = NULL; 
	free(array);
	return (final_array);
}

void	ft_free_pipex1(char ***altv)
{
	int	i;

	i = 0;
	while ((*altv)[i + 1] != NULL)
	{
		free((*altv)[i]);
		i++;
	}
	free(*altv);
}

void	ft_free_pipex2(char ***altv)
{
	int	i;

	i = 0;
	while ((*altv)[i] != NULL)
	{
		free((*altv)[i]);
		i++;
	}
	free(*altv);
}