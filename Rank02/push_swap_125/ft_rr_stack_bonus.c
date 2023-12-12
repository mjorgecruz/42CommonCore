/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:38:49 by masoares          #+#    #+#             */
/*   Updated: 2023/11/24 18:04:08 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	rra_bonus(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	temp = NULL;
	last = NULL;
	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return (1);
	last = ft_lstlast_ps_bonus(*stack_a);
	if (last == NULL)
		return (1);
	temp = (*stack_a);
	(*stack_a)->prev = last; 
	last->prev->next = NULL;
	last->prev = NULL;
	(*stack_a) = last;
	(*stack_a)->next = temp;
	return (0);
}

int	rrb_bonus(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*last;

	temp = NULL;
	last = NULL;
	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return (1);
	last = ft_lstlast_ps_bonus(*stack_b);
	if (last == NULL)
		return (1);
	temp = (*stack_b);
	last->prev->next = NULL;
	last->prev = NULL;
	(*stack_b)->prev = last; 
	(*stack_b) = last;
	(*stack_b)->next = temp;
	return (0);
}

int	rrr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	rra_bonus(stack_a);
	rrb_bonus(stack_b);
	return (1);
}
