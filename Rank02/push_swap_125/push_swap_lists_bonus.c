/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lists_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:41:31 by masoares          #+#    #+#             */
/*   Updated: 2023/11/29 15:07:53 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*ft_lstnew_ps_bonus(int num)
{
	t_stack	*stack;

	stack = (t_stack *) malloc (sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->num = num;
	stack->index = 0;
	stack->targ = NULL;
	stack->m_cost = 0;
	stack->ab_med = false;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

void	ft_lstadd_back_ps_bonus(t_stack **lst, t_stack **new)
{
	t_stack	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = *new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = *new;
		(*new)->prev = temp;
	}
}

void	ft_lstclear_ps_bonus(t_stack **lst)
{
	t_stack	*current;
	t_stack	*trav;

	current = *lst;
	while (current != NULL)
	{
		trav = current->next;
		free(current);
		current = trav;
	}
	*lst = NULL;
}

t_stack	*ft_lstlast_ps_bonus(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize_ps_bonus(t_stack *lst)
{
	int		count;
	t_stack	*trav;

	count = 0;
	trav = lst;
	while (trav != NULL)
	{
		count++;
		trav = trav->next;
	}
	return (count);
}
