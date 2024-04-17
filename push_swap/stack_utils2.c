/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:37:03 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/17 10:59:07 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted_stack(t_stack *stk)
{
	if (!stk)
		return (true);
	while (stk->next)
	{
		if (stk->next->val < stk->val)
			return (false);
		stk = stk->next;
	}
	return (true);
}

t_stack	*get_max_node(t_stack *stk)
{
	int		max;
	t_stack	*max_node;

	max = INT_MIN;
	if (!stk)
		return (NULL);
	while (stk)
	{
		if (stk->val > max)
		{
			max = stk->val;
			max_node = stk;
		}
		stk = stk->next;
	}
	return (max_node);
}

void	handle_five(t_stack **a, t_stack **b)
{
	while (get_stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, get_smallest_node(*a), 'a');
		pb(b, a);
	}
}
