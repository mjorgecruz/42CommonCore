/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:37:57 by masoares          #+#    #+#             */
/*   Updated: 2023/11/24 18:04:12 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	sa_bonus(t_stack **stack_a)
{
	t_stack	*temp;

	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return (1);
	temp = (*stack_a)->next->next;
	(*stack_a) = (*stack_a)->next;
	(*stack_a)->next = (*stack_a)->prev;
	if (temp == NULL)
		(*stack_a)->next->next = NULL;
	else
		(*stack_a)->next->next = temp;
	(*stack_a)->prev = NULL;
	(*stack_a)->next->prev = (*stack_a);
	if (temp != NULL)
		temp->prev = (*stack_a)->next;
	return (0);
}

int	sb_bonus(t_stack **stack_b)
{
	t_stack	*temp;

	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return (1);
	temp = (*stack_b)->next->next;
	(*stack_b) = (*stack_b)->next;
	(*stack_b)->next = (*stack_b)->prev;
	if (temp == NULL)
		(*stack_b)->next->next = NULL;
	else
		(*stack_b)->next->next = temp;
	(*stack_b)->prev = NULL;
	(*stack_b)->next->prev = (*stack_b);
	if (temp != NULL)
		temp->prev = (*stack_b)->next;
	return (0);
}

int	ss_bonus(t_stack **stack_a, t_stack **stack_b)
{
	if (sa_bonus(stack_a) == 1 || sb_bonus(stack_b) == 1)
	{
		return (1);
	}
	return (0);
}
