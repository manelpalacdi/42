/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:49:08 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/17 12:50:42 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_error(char *str)
{
	int	i;

	i = 0;
	if (str[0] != '+' && str[0] != '-' && !ft_isdigit(str[0]))
			return (1);
	if ((str[0] == '+' || str[0] == '-')
			&& !ft_isdigit(str[1]))
		return (1);
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	repetition_error(t_stack *stk, int nbr)
{
	if (!stk)
		return (0);
	while (stk)
	{
		if (stk->val == nbr)
			return (1);
		stk = stk->next;
	}
	return (0);
}

void error_free(t_stack **stk, char **argv, bool argc_equals_2)
{
	free_stack(stk);
	if (argc_equals_2)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}

void free_stack(t_stack **stk)
{
	t_stack *aux;
	t_stack *current;

	if (!stk)
		return ;
	current = *stk;
	while(current)
	{
		aux = current->next;
		free(current);
		current = aux;
	}
	*stk = NULL;
}

void free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix || !matrix[0])
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
