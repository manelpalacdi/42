/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:20:34 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/22 12:01:07 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack **a)
{
	t_stack	*max_node;

	max_node = get_max_node(*a);
	if (*a == max_node)
		ra(a);
	else if ((*a)->next == max_node)
		rra(a);
	if ((*a)->val > (*a)->next->val)
		sa(a);
}
