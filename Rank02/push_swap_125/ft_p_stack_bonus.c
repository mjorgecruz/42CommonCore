/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:38:11 by masoares          #+#    #+#             */
/*   Updated: 2023/11/24 17:51:27 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	pa_bonus(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (stack_b == NULL || *stack_b == NULL)
		return (1);
	temp = (*stack_b);
	temp2 = (*stack_a);
	(*stack_a) = temp;
	(*stack_b)->prev = NULL;
	if (temp->next == NULL)
		(*stack_b) = NULL;
	else
	{
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->prev = NULL;
	}
	if (temp2 == NULL)
		(*stack_a)->next = NULL;
	else
	{
		(*stack_a)->next = temp2;
		(*stack_a)->next->prev = (*stack_a);
	}
	return (0);
}

int	pb_bonus(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (stack_a == NULL || *stack_a == NULL)
		return (1);
	temp = (*stack_a);
	temp2 = (*stack_b);
	(*stack_b) = temp;
	(*stack_a)->prev = NULL;
	if (temp->next == NULL)
		(*stack_a) = NULL;
	else
	{
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->prev = NULL;
	}
	if (temp2 == NULL)
		(*stack_b)->next = NULL;
	else
	{
		(*stack_b)->next = temp2;
		(*stack_b)->next->prev = (*stack_b);
	}
	return (0);
}
