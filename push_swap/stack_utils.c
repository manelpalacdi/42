/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:29:46 by mpalacin          #+#    #+#             */
/*   Updated: 2024/03/14 13:06:14 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack **stk, int val)
{
	t_stack	*new_node;
	t_stack	*last_node;
	
	if (!stk)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->val = val;
	new_node->next = NULL;
	if (!(*stk))
	{
		*stk = new_node;
		new_node->previous = NULL;
	}
	else
	{
		*last_node = get_last_node(t_stack *stk);
		last_node->next = new_node;
		new_node->previous = last_node;
	}
}

t_stack	*get_last_node(t_stack *stk)
{
	if (!stk)
		return (NULL);
	while (stk->next)
		stk = stk->next;
	return (stk);
}

int	get_stack_len(t_stack *stk)
{
	int	len;

	len = 0;
	while (stk)
	{
		stk = stk->next;
		len++;
	}
	return (len);
}

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
