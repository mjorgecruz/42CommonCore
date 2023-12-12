/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_s_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:22:39 by masoares          #+#    #+#             */
/*   Updated: 2023/11/24 17:40:33 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	maximum(t_stack **st)
{
	t_stack	*ptr;
	int		i;

	ptr = *st;
	i = (*st)->num;
	while (ptr != NULL)
	{
		if (ptr->num > i)
			i = ptr->num;
		ptr = ptr->next; 
	}
	return (i);
}

int	minimum(t_stack **st)
{
	t_stack	*ptr;
	int		j;

	ptr = *st;
	j = (*st)->num;
	while (ptr != NULL)
	{
		if (ptr->num < j)
			j = ptr->num;
		ptr = ptr->next;
	}
	return (j);
}

void	ft_cost(t_stack *sta, t_stack *stb)
{
	int	ac;
	int	bc;
	int	min;

	ac = ft_lstsize_ps(sta);
	bc = ft_lstsize_ps(stb);
	while (sta)
	{
		min = find_min(sta, &stb);
		sta->targ = find_index(min, &stb);
		if (sta->ab_med == false && sta->targ->ab_med == false)
			sta->m_cost = ft_abab(sta, ac, bc);
		else if (sta->ab_med == true && sta->targ->ab_med == true)
			sta->m_cost = ft_baba(sta);
		else
			ft_baababba(sta, ac, bc);
		sta = sta->next;
	}
}

t_stack	*find_index(int min, t_stack **stb)
{
	t_stack	*ptr;

	ptr = *stb;
	while (ptr != NULL)
	{
		if (ptr->num == min)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

int	ft_baababba(t_stack *sta, int ac, int bc)
{
	if (sta->ab_med == false)
		sta->m_cost = ac - sta->index;
	else
		sta->m_cost = sta->index;
	if (sta->targ->ab_med == false)
		sta->m_cost += bc - sta->targ->index;
	else
		sta->m_cost += sta->targ->index;
	return (0);
}
