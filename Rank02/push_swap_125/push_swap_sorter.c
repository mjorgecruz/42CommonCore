/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:35:12 by masoares          #+#    #+#             */
/*   Updated: 2023/11/27 15:28:14 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack **st)
{
	t_stack	*ptr;

	ptr = *st;
	while (ptr->next != NULL)
	{
		if (ptr->num > ptr->next->num)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int	mega_sorter(t_stack **sta, t_stack **stb)
{
	if (check_sorted(sta) == 0)
		return (0);
	if (ft_lstsize_ps(*sta) < 5)
	{
		minisort(sta, stb);
		return (0);
	}
	pb(sta, stb);
	pb(sta, stb);
	while ((*stb))
	{
		mega_sorter_decider(sta, stb);
		mega_sorter_decider2(sta, stb);
	}
	if (!(*stb))
	{
		def_index(sta);
		rotate_min_top(sta);
		return (0);
	}
	return (0);
}

int	mega_sorter_decider(t_stack **sta, t_stack **stb)
{
	while (*sta != NULL)
	{
		if (ft_lstsize_ps(*sta) <= 3)
		{
			sort_threes(sta);
			return (1);
		}
		def_index(sta);
		def_index(stb);
		cost_def_pb(*sta, *stb);
		make_move_pb(sta, stb);
	}
	return (0);
}

int	mega_sorter_decider2(t_stack **sta, t_stack **stb)
{
	while (*stb != NULL)
	{
		if (!(*stb))
			return (2);
		def_index(sta);
		def_index(stb);
		cost_def_pa(*sta, *stb);
		make_move_pa(sta, stb);
	}
	return (1);
}

void	rotate_min_top(t_stack **sta)
{
	int		min;
	t_stack	*sta_min;

	min = minimum(sta);
	sta_min = find_index(min, sta);
	while ((*sta) != sta_min)
	{
		if (sta_min->ab_med == true)
			ra(sta, 0);
		else
			rra(sta, 0);
	}
}
