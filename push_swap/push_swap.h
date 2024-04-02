/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:10:23 by mpalacin          #+#    #+#             */
/*   Updated: 2024/03/14 13:46:59 by mpalacin         ###   ########.fr       */
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
int		syntax_error(char *str);
int		repetition_error(t_stack *stk, int nbr);
void	error_free(t_stack **stk, char **argv, bool argc_equals_2);
void	free_stack(t_stack **stk);
void	free_matrix(char **matrix);
void	append_node(t_stack **stk, int val);
t_stack	get_last_node(t_stack *stk);
bool	sorted_stack(t_stack *stk);
int		get_stack_len(t_stack *stk);
#endif
