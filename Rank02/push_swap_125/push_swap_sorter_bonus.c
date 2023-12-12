/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorter_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:35:12 by masoares          #+#    #+#             */
/*   Updated: 2023/11/24 19:51:26 by masoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_sorted_bonus(t_stack **st)
{
	t_stack	*ptr;

	ptr = *st;
	while (ptr->next != NULL)
	{
		if (ptr->num > ptr->next->num)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
