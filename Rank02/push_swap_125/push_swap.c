/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:24:41 by masoares          #+#    #+#             */
/*   Updated: 2023/11/27 16:05:28 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*sta;
	t_stack	*stb;
	int		str;
	char	**splited;

	splited = NULL;
	sta = NULL;
	stb = NULL;
	str = 0;
	if (ac == 2)
	{
		if (av[1][0] == '\0')
			return (write(STDERR_FILENO, "Error\n", 6), 1);
		splited = spliter(&ac, av, &str);
	}
	else if (ac > 2)
		splited = more_than_two(&ac, av);
	else
		return (1);
	if (check_errors(ac, splited) == 0)
		push_swap(ac, splited, &sta, &stb);
	if (str == 1)
		split_free(splited);
	return (0);
}

int	push_swap(int ac, char **av, t_stack **sta, t_stack **stb)
{
	create_t_sta(ac, av, sta);
	mega_sorter(sta, stb);
	ft_lstclear_ps(sta);
	return (0);
}

int	split_free(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
	free(av);
	return (0);
}

char	**spliter(int *ac, char **av, int *str)
{
	char	**splited;

	splited = NULL;
	*ac = count_words(av[1], ' ');
	splited = ft_split(av[1], ' ');
	*str = 1;
	return (splited);
}

char	**more_than_two(int *ac, char	**av)
{
	char	**splited;

	*ac = *ac - 1;
	splited = av + 1;
	return (splited);
}
