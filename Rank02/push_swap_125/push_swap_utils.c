/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:07:49 by masoares          #+#    #+#             */
/*   Updated: 2023/11/27 09:50:12 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_t_sta(int ac, char **nums, t_stack **sta)
{
	int		i;
	t_stack	*new;

	i = 0;
	while (i < ac)
	{
		new = ft_lstnew_ps(ft_atoi(nums[i]));
		ft_lstadd_back_ps(sta, &new);
		i++;
	}
}

void	minisort(t_stack **sta, t_stack **stb)
{
	if (ft_lstsize_ps(*sta) == 2)
	{
		if ((*sta)->num > (*sta)->next->num)
			sa(sta, 0);
	}
	else if (ft_lstsize_ps(*sta) == 3)
		sort_threes(sta);
	else if (ft_lstsize_ps(*sta) < 5)
		sort_fours(sta, stb);
}

void	sort_threes(t_stack **sta)
{
	if ((*sta)->next->num > (*sta)->num)
	{
		if ((*sta)->num < (ft_lstlast_ps(*sta))->num)
		{
			if ((ft_lstlast_ps(*sta))->num < (*sta)->next->num)
			{
				rra(sta, 0);
				sa(sta, 0);
			}
		}
		else
			rra(sta, 0);
	}
	else if ((*sta)->next->num < (*sta)->num)
		sort_threes_biggernext(sta);
}

void	sort_threes_biggernext(t_stack **sta)
{
	if ((*sta)->num < (ft_lstlast_ps(*sta))->num)
		sa(sta, 0);
	else if ((*sta)->num > (ft_lstlast_ps(*sta))->num)
	{
		if ((ft_lstlast_ps(*sta))->num < (*sta)->next->num)
		{
			sa(sta, 0);
			rra(sta, 0);
		}
		else
			ra(sta, 0);
	}
}

void	sort_fours(t_stack **sta, t_stack **stb)
{
	pb(sta, stb);
	sort_threes(sta);
	if ((*stb)->num > ft_lstlast_ps(*sta)->num)
	{
		pa(sta, stb);
		ra(sta, 0);
	}
	else if ((*stb)->num < (*sta)->num)
		pa(sta, stb);
	else
	{
		while ((*stb)->num > (*sta)->num)
			ra(sta, 0);
		pa(sta, stb);
		while (check_sorted(sta) != 0)
			ra(sta, 0);
	}
}

// int	print_nums(t_stack **sta, t_stack **stb)
// {
// 	t_stack	*ptr;
// 	t_stack	*ptr2;

// 	ptr = (*sta);
// 	ptr2 = *stb;
// 	while (ptr != NULL && ptr2 != NULL)
// 	{
// 		ft_printf("%d   %d\n", ptr->num, ptr2->num);
// 		ptr = ptr->next;
// 		ptr2 = ptr2->next;
// 	}
// 	if (ptr == NULL)
// 	{
// 		while (ptr2 != NULL)
// 		{
// 			ft_printf("[]  %d\n", ptr2->num);
// 			ptr2 = ptr2->next;
// 		}
// 	}
// 	if (ptr2 == NULL)
// 	{
// 		while (ptr != NULL)
// 		{
// 			ft_printf("%d  []\n", ptr->num);
// 			ptr = ptr->next;
// 		}
// 	}
// 	return (0);
// }
