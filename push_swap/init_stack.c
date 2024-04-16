/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:06:09 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/16 12:56:53 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	_atol(const char *str)
{
	int	neg;
	int	nb;

	neg = 1;
	nb = 0;
	while (ft_isspace(str[0]))
		str++;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			neg = -1;
		str++;
	}
	while (str[0] && ft_isdigit(str[0]))
	{
		nb = nb * 10 + str[0] - 48;
		str++;
	}
	return (nb * neg);
}
void	init_stack(t_stack **a, char **argv, bool argc_equals_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			error_free(a, argv, argc_equals_2);
		nbr = _atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, argc_equals_2);
		if (repetition_error(*a, (int)nbr))
			error_free(a, argv, argc_equals_2);
		append_node(a, (int)nbr);
		i++;
	}
	if (argc_equals_2)
		free_matrix(argv);
}
