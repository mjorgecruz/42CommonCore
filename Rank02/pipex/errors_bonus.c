/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:48:34 by masoares          #+#    #+#             */
/*   Updated: 2023/12/19 10:00:30 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void    errors_bonus(int num, char *str, t_data *data)
{
        int     len;
        len = 0;
        if (num == 2)
        {
                write(STDERR_FILENO, "Error: command not found: ", 26);
		len = ft_strlen(str);
		write(STDERR_FILENO, str, len);
		free_p1_bonus(&(data->altv1));
		free_p2_bonus(&(data->altv2));
		exit(EXIT_FAILURE);
        }
}