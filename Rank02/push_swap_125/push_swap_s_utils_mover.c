/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_s_utils_mover.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:22:39 by masoares          #+#    #+#             */
/*   Updated: 2023/11/27 14:45:53 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_move_pb(t_stack **sta, t_stack **stb)
{
	int		min;
	t_stack	*ptr;

	ptr = *sta;
	min = search_lowcost(sta);
	while (ptr != NULL)
	{
		if (ptr->m_cost == min)
			break ;
		ptr = ptr->next;
	}
	if (ptr->ab_med == true && ptr->targ->ab_med == true)
		both_ab_median(ptr, sta, stb);
	else if (ptr->ab_med == false && ptr->targ->ab_med == false)
		both_bl_median(ptr, sta, stb);
	other_cases(ptr, sta, 1);
	other_cases(ptr->targ, stb, 0);
	pb(sta, stb);
}

void	make_move_pa(t_stack **sta, t_stack **stb)
{
	while ((*sta) != (*stb)->targ && (*stb))
	{
		if ((*stb)->targ->ab_med == true)
			ra(sta, 0);
		else
			rra(sta, 0);
	}
	pa(sta, stb);
}

int	both_ab_median(t_stack *ptr, t_stack **sta, t_stack **stb)
{
	while (*sta != ptr && *stb != ptr->targ)
		rr(sta, stb);
	return (0);
}

int	both_bl_median(t_stack *ptr, t_stack **sta, t_stack **stb)
{
	while (*sta != ptr && *stb != ptr->targ)
		rrr(sta, stb);
	return (0);
}

int	other_cases(t_stack *ptr, t_stack **stc, int x)
{
	while (*stc != ptr)
	{
		if (x == 1)
		{
			if (ptr->ab_med == true)
				ra(stc, 0);
			else
				rra(stc, 0);
		}
		else
		{
			if (ptr->ab_med == true)
				rb(stc, 0);
			else
				rrb(stc, 0);
		}
	}
	return (0);
}
