#include "push_swap.h"

static void	_rotate(t_stack **stack)
{
	t_stack	*last_node;
	int	len;

	len = get_stack_len(*stack);
	if (!stack || !(*stack) || len == 1)
		return ;
	last_node = get_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	last_node->next->previous = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}