/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:59:44 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/17 13:02:18 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(t_stack *a)
{
	int	i;
	int	center;

	i = 0;
	center = get_stack_len(a) / 2;
	while (a)
	{
		a->pos = i;
		if (i >= center)
			a->above_median = true;
		else
			a->above_median = false;
		a = a->next;
		i++;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = get_stack_len(a);
	len_b = get_stack_len(b);
	while (b)
	{
		b->push_cost = b->pos;
		if (!(b->above_median))
			b->push_cost = len_b - b->pos;
		if (b->target_node->above_median)
			b->push_cost += b->target_node->pos;
		else
			b->push_cost += len_a - b->target_node->pos;
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	long	best;
	t_stack	*best_node;

	if (!b)
		return ;
	best = LONG_MAX;
	while (b)
	{
		if (b->push_cost < best)
		{
			best = b->push_cost;
			best_node = b;
		}
		b = b->next;
	}
	best_node->cheapest = true;
}

void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best;

	while (b)
	{
		best = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->val > b->val
				&& current_a->val < best)
			{
				best = current_a->val;
				target_node = current_a;
			}
			current_a = current_a->next;
			if (LONG_MAX == best)
				b->target_node = get_smallest_node(a);
			else
				b->target_node = target_node;
		}
		b = b->next;
	}
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
