#include "push_swap.h"

static void	_reverse_rotate(t_stack **stack)
{
	t_stack	*last_node;
	int	len;

	len = get_stack_len(*stack);
	if (!(*stack) || !stack || len == 1)
		return ;
	last_node = get_last_node(*stack);
	last_node->previous->next = NULL;
	last_node->next = *stack;
	last_node->previous = NULL;
	*stack = last_node;
	last_node->next->previous = last_node;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
