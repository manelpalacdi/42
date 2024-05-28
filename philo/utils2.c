/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:26:22 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/28 11:48:12 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
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
