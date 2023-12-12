/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:38:49 by masoares          #+#    #+#             */
/*   Updated: 2023/11/21 15:11:18 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack **stack_a, int n)
{
	t_stack	*temp;
	t_stack	*last;

	temp = NULL;
	last = NULL;
	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return (1);
	last = ft_lstlast_ps(*stack_a);
	if (last == NULL)
		return (1);
	temp = (*stack_a);
	(*stack_a)->prev = last; 
	last->prev->next = NULL;
	last->prev = NULL;
	(*stack_a) = last;
	(*stack_a)->next = temp;
	if (n == 0)
		ft_printf("rra\n");
	return (0);
}

int	rrb(t_stack **stack_b, int n)
{
	t_stack	*temp;
	t_stack	*last;

	temp = NULL;
	last = NULL;
	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return (1);
	last = ft_lstlast_ps(*stack_b);
	if (last == NULL)
		return (1);
	temp = (*stack_b);
	last->prev->next = NULL;
	last->prev = NULL;
	(*stack_b)->prev = last; 
	(*stack_b) = last;
	(*stack_b)->next = temp;
	if (n == 0)
		ft_printf("rrb\n");
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b )
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	ft_printf("rrr\n");
	return (1);
}
