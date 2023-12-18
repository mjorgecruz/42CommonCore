/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:17:15 by masoares          #+#    #+#             */
/*   Updated: 2023/12/01 10:00:35 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base_searcher(char c, char *base, int base_dim);

int	ft_atoi_base(char *str, int base_dim)
{
	int		i;
	int		neg;
	long	value;
	char    *base = "0123456789abcdef";
	int		j;
	char	*str_new;

	str_new = (char *) malloc(sizeof(char)*(ft_strlen(str) + 1));
	i = 0;
	while (str[i] != '\0')
	{
		str_new[i] = ft_tolower(str[i]);
		i++;
	}
	str_new[i] = '\0';
	i = 0;
	neg = 1;
	value = 0;
	while ((*(str_new + i) >= 9 && *(str_new + i) <= 13) || *(str_new + i) == 32)
		i++;
	if (*(str_new + i) == '+' || *(str_new + i) == '-')
	{
		if (*(str_new + i) == '-')
			neg = -1;
		i++;
	}
	j = 0;
	while (j > -1 && *(str_new + i) != '\0')
	{
		j = base_searcher(*(str_new + i), base, base_dim);
		value = value * base_dim;
		value = value + j;
		i++;
	}
	value = value * neg;
	free(str_new);
	return (value);
}

static int	base_searcher(char c, char *base, int base_dim)
{
	int		i;

	i = 0;
	while(i < base_dim)
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
