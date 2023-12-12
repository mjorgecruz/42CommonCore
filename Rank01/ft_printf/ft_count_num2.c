/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_num2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:53:25 by masoares          #+#    #+#             */
/*   Updated: 2023/10/14 15:47:37 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_num2(unsigned int nbr, int size)
{
	unsigned long	num;
	int				count;

	num = nbr;
	count = 0;
	if (nbr == 0)
		count = 1;
	while (num > 0)
	{
		count++;
		num = num / size;
	}
	return (count);
}
