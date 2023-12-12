/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_s_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:22:39 by masoares          #+#    #+#             */
/*   Updated: 2023/11/23 15:45:20 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *st, t_stack **stb)
{
	t_stack	*ptr;
	int		max;
	int		min;

	ptr = *stb;
	max = maximum(stb);
	min = minimum(stb);
	if (min > st->num)
		return (max);
	while (ptr != NULL)
	{
		if (ptr->num > min && ptr->num < st->num)
			min = ptr->num;
		ptr = ptr->next;
	}
	return (min);
}

int	find_max(t_stack *st, t_stack **sta)
{
	t_stack	*ptr;
	int		max;
	int		min;

	ptr = *sta;
	max = maximum(sta);
	min = minimum(sta);
	if (max < st->num)
		return (min);
	while (ptr != NULL)
	{
		if (ptr->num < max && ptr->num > st->num)
			max = ptr->num;
		ptr = ptr->next;
	}
	return (max);
}

int	cost_def_pb(t_stack *sta, t_stack *stb)
{
	ft_cost(sta, stb);
	return (0);
}

int	cost_def_pa(t_stack *sta, t_stack *stb)
{
	int		max;

	max = 0;
	while (stb != NULL)
	{
		max = find_max(stb, &sta);
		stb->targ = find_index(max, &sta);
		stb = stb->next;
	}
	return (0);
}

int	search_lowcost(t_stack **st)
{
	t_stack	*ptr;
	int		min;

	ptr = *st;
	min = (*st)->m_cost;
	while (ptr != NULL)
	{
		if (ptr->m_cost < min)
			min = ptr->m_cost;
		ptr = ptr->next;
	}
	return (min);
}
