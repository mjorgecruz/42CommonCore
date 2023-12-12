/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:38:38 by masoares          #+#    #+#             */
/*   Updated: 2023/11/21 15:12:57 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **stack_a, int n)
{
	t_stack	*temp;
	t_stack	*last;

	temp = NULL;
	last = NULL;
	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return (1);
	last = ft_lstlast_ps(*stack_a);
	temp = (*stack_a);
	(*stack_a)->next->prev = NULL; 
	last->next = temp;
	temp->prev = last;
	(*stack_a) = (*stack_a)->next;
	last = temp;
	last->next = NULL;
	(*stack_a)->prev = NULL;
	if (n == 0)
		ft_printf("ra\n");
	return (0);
}

int	rb(t_stack **stack_b, int n)
{
	t_stack	*temp;
	t_stack	*last;

	temp = NULL;
	last = NULL;
	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return (1);
	last = ft_lstlast_ps(*stack_b);
	temp = (*stack_b);
	(*stack_b)->next->prev = NULL; 
	last->next = temp;
	temp->prev = last;
	(*stack_b) = (*stack_b)->next;
	last = temp;
	last->next = NULL;
	(*stack_b)->prev = NULL;
	if (n == 0)
		ft_printf("rb\n");
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	ft_printf("rr\n");
	return (0);
}
