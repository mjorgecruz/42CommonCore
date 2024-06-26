/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:18:51 by masoares          #+#    #+#             */
/*   Updated: 2023/11/10 15:40:25 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	value;

	i = 0;
	neg = 1;
	value = 0;
	while ((*(str + i) >= 9 && *(str + i) <= 13) || *(str + i) == 32)
		i++;
	if (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			neg = -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		value = value * 10;
		value = value + *(str + i) - '0';
		i++;
	}
	value = value * neg;
	return (value);
}
/*
int main () {
   int val;

   val = ft_atoi("\n\n\n  -46\b9 \n5d6");
   printf("Int value = %d\n", val);

   return(0);
}
*/