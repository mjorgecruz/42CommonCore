/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:07:49 by masoares          #+#    #+#             */
/*   Updated: 2023/11/29 15:41:12 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	create_t_sta_bonus(int ac, char **nums, t_stack **sta)
{
	int		i;
	t_stack	*new;

	i = 0;
	while (i < ac)
	{
		new = ft_lstnew_ps_bonus(ft_atoi(nums[i]));
		ft_lstadd_back_ps_bonus(sta, &new);
		i++;
	}
}

char	**more_than_two_bonus(int *ac, char **av)
{
	char	**splited;

	*ac = *ac - 1;
	splited = av + 1;
	return (splited);
}

int	checker(int ac, char **splited, t_stack **sta, t_stack **stb)
{
	create_t_sta_bonus(ac, splited, sta);
	mega_checker(sta, stb, ac);
	ft_lstclear_ps_bonus(sta);
	ft_lstclear_ps_bonus(stb);
	return (1);
}
