/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:27:28 by mpalacin          #+#    #+#             */
/*   Updated: 2024/03/07 12:59:02 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	_check_no_int_input(int argc, char **argv)
{
	int			i;
	int			j;
	long int	num_arg;

	i = 0;
	j = 0;
	while (i < argc)
	{
		if (!argv[i][0])
			return (1);
		num_arg = ft_atoi(argv[i]);
		if (num_arg > INT_MAX || num_arg < INT_MIN)
			return (1);
		if (num_arg == 0)
		{
			while (argv[i][j])
			{
				if (!ft_isdigit(argv[i][j]))
					return (1);
			}
		}
		i++;
	}
}

int	_check_no_duplicate_input(int argc, char *argv)
{
	int	i;
	int	j;
	int	*input;

	i = 0;
	j = 0;
	input = malloc(argc * sizeof(int));
	if (!num_lst)
		return (1);
	while (i < argc)
	{
		input[i] = ft_atoi(argv[i]);
		while (j < i)
		{
			if (input[i] == input[j])
				return (free(input), 1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*tmp;
	int		i;

	i = 0;
	if (!argc)
		return (0);
	if (_check_no_int_input(argc, argv))
		return (write(2, "Error\n", 6), 0);
	if (_check_no_duplicate_input(argc, argv))
		return (write(2, "Error\n", 6), 0);
	while (i < argc)
	{
		node = ft_lstnew(ft_atoi(argv[argc - i - 1]));
		if (!node)
			return (write(2, "Error\n", 6), 0);
		printf("%d ", node->content);
		ft_push(&lst, node);
	}
}
