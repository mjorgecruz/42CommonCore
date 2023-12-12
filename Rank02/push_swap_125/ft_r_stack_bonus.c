/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:38:38 by masoares          #+#    #+#             */
/*   Updated: 2023/11/24 18:03:50 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ra_bonus(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	temp = NULL;
	last = NULL;
	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return (1);
	last = ft_lstlast_ps_bonus(*stack_a);
	temp = (*stack_a);
	(*stack_a)->next->prev = NULL; 
	last->next = temp;
	temp->prev = last;
	(*stack_a) = (*stack_a)->next;
	last = temp;
	last->next = NULL;
	(*stack_a)->prev = NULL;
	return (0);
}

int	rb_bonus(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*last;

	temp = NULL;
	last = NULL;
	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return (1);
	last = ft_lstlast_ps_bonus(*stack_b);
	temp = (*stack_b);
	(*stack_b)->next->prev = NULL; 
	last->next = temp;
	temp->prev = last;
	(*stack_b) = (*stack_b)->next;
	last = temp;
	last->next = NULL;
	(*stack_b)->prev = NULL;
	return (0);
}

int	rr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	ra_bonus(stack_a);
	rb_bonus(stack_b);
	return (0);
}
