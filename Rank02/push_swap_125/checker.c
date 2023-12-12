/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:59:05 by masoares          #+#    #+#             */
/*   Updated: 2023/11/29 15:50:29 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	mega_checker(t_stack **sta, t_stack **stb, int ac);
int	check_cases(char *line, t_stack **sta, t_stack **stb);

int	main(int ac, char **av)
{
	t_stack	*sta;
	t_stack	*stb;
	int		str;
	char	**splited;

	splited = NULL;
	str = 0;
	sta = NULL;
	stb = NULL;
	if (ac == 2)
	{
		if (av[1][0] == '\0')
			return (write(STDERR_FILENO, "Error\n", 6), 1);
		splited = spliter_bonus(&ac, av, &str);
	}
	else if (ac > 2)
		splited = more_than_two_bonus(&ac, av);
	else
		return (1);
	if (check_errors_bonus(ac, splited) == 0)
		checker(ac, splited, &sta, &stb);
	if (str == 1)
		split_free_bonus(splited);
	return (ft_lstclear_ps_bonus(&sta), ft_lstclear_ps_bonus(&stb), 0);
}

int	mega_checker(t_stack **sta, t_stack **stb, int ac)
{
	char	line[20];
	int		i;
	int		c;

	i = 0;
	c = 1;
	while (c != 0)
	{
		c = read(STDIN_FILENO, line, 20);
		line[c] = '\0';
		i = check_cases(line, sta, stb);
		if (i == 1)
		{
			write (1, "Error\n", 6);
			ft_lstclear_ps_bonus(sta);
			ft_lstclear_ps_bonus(stb);
			return (0);
		}
	}
	if (*stb == NULL && check_sorted_bonus(sta) == 0 
		&& ft_lstsize_ps_bonus(*sta) == ac)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	return (0);
}

int	check_cases(char *line, t_stack **sta, t_stack **stb)
{
	if (ft_strcmp(line, "rr\n") == 0)
		return (rr_bonus(sta, stb), 0);
	else if (ft_strcmp(line, "ra\n") == 0)
		return (ra_bonus(sta), 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		return (rb_bonus(stb), 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		return (rrr_bonus(sta, stb), 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		return (rra_bonus(sta), 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		return (rrb_bonus(stb), 0); 
	else if (ft_strcmp(line, "sa\n") == 0)
		return (sa_bonus(sta), 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		return (sb_bonus(sta), 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		return (ss_bonus(sta, stb), 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		return (pa_bonus(sta, stb), 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		return (pb_bonus(sta, stb), 0);
	else if (!(*line))
		return (0);
	return (1);
}

int	split_free_bonus(char **av)
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

char	**spliter_bonus(int *ac, char **av, int *str)
{
	char	**splited;

	splited = NULL;
	*ac = count_words(av[1], ' ');
	splited = ft_split(av[1], ' ');
	*str = 1;
	return (splited);
}
