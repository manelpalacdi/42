/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:10:23 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/15 12:27:19 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_stack
{
	int	val;
	int	pos;
	int	push_cost;
	bool	above_median;
	bool	cheapest;
	struct	s_list	target_node;
	struct	s_list	*previous;
	struct	s_list	*next;
}	t_stack;
char	**ft_split(char const *str, char c);
void	init_stack(t_stack **stk, char **argv, bool argc_equals_2);
int	syntax_error(char *str);
int	repetition_error(t_stack *stk, int nbr);
void	error_free(t_stack **stk, char **argv, bool argc_equals_2);
void	free_stack(t_stack **stk);
void	free_matrix(char **matrix);
void	append_node(t_stack **stk, int val);
t_stack	get_last_node(t_stack *stk);
bool	sorted_stack(t_stack *stk);
int	get_stack_len(t_stack *stk);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void    pa(t_stack **a);
void    pb(t_stack **b);
void	tiny_sort(t_stack **a);
#endif
