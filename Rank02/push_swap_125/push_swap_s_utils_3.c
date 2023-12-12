/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_s_utils_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:22:39 by masoares          #+#    #+#             */
/*   Updated: 2023/11/29 09:04:53 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	def_index(t_stack **st)
{
	t_stack	*ptr;
	int		index;
	int		ac;

	ac = ft_lstsize_ps(*st);
	ptr = *st;
	index = 0;
	while (ptr != NULL)
	{
		ptr->index = index;
		ptr->targ = NULL;
		if (ptr->index <= ac / 2)
			ptr->ab_med = true;
		else
			ptr->ab_med = false;
		index++;
		ptr = ptr->next;
	}
	return (0);
}

int	ft_abab(t_stack *sta, int ac, int bc)
{
	if (ac - sta->index > bc - sta->targ->index)
		return (ac - sta->index);
	else
		return (bc - sta->targ->index);
}

int	ft_baba(t_stack *sta)
{
	if (sta->index < sta->targ->index)
		return (sta->targ->index);
	else
		return (sta->index);
}

// void	sort_fives(t_stack **sta, t_stack **stb)
// {
// 	if ((*sta)->num > ft_lstlast_ps(*sta)->num)
// 		rra(sta, 0);
// 	pb(sta, stb);
// 	if ((*sta)->num > ft_lstlast_ps(*sta)->num)
// 		rra(sta, 0);
// 	pb(sta, stb);
// 	if ((*stb)->num < (*stb)->next->num)
// 		sa(stb, 0);
// 	sort_threes(sta);
// 	mega_sorter_decider2(sta, stb);
// }