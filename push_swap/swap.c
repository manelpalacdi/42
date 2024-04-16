#include "push_swap.h"

static void	_swap(t_stack **head)
{
	int	len;

	len = get_stack_len(*head);
	if (!(*head) || !head || len == 1)
		return ;
	*head = (*head)->next;
	(*head)->previous->previous = *head;
	(*head)->previous->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->previous = (*head)->previous;
	(*head)->next = (*head)->previous;
	(*head)->previous = NULL;
}

void	sa(t_stack **a)
{
	_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	_swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	_swap(a);
	_swap(b);
	write(1, "ss\n", 3);
}
