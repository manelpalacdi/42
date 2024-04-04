/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:03:43 by mpalacin          #+#    #+#             */
/*   Updated: 2024/01/24 12:45:46 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countdig(int n)
{
	int	count;

	count = 1;
	while (n / 10 > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_doloop(char *itoa, int neg, int n)
{
	int	i;
	int	dig_count;
	int	dig;

	i = 0;
	dig_count = ft_countdig(n);
	while (i < dig_count)
	{
		dig = n % 10 + 48;
		itoa[dig_count - i - 1 + neg] = dig;
		n = n / 10;
		i++;
	}
	itoa[dig_count + neg] = '\0';
	return (itoa);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		dig_count;
	int		neg;

	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	dig_count = ft_countdig(n);
	if (n != -2147483648)
	{
		itoa = malloc((dig_count + neg + 1) * sizeof(char));
		if (!itoa)
			return (NULL);
		if (neg == 1)
			itoa[0] = '-';
		return (ft_doloop(itoa, neg, n));
	}
	return (ft_strdup("-2147483648"));
}
