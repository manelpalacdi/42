/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _printnumbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:59:11 by mpalacin          #+#    #+#             */
/*   Updated: 2024/02/06 12:04:06 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printdecimalnbr(long long int n, long long int *printcount)
{
	if (n < 0)
	{
		printchar('-', printcount);
		n *= -1;
	}
	if (n >= 10)
		printdecimalnbr(n / 10, printcount);
	printchar("0123456789"[n % 10], printcount);
}

void	printbasenbr(unsigned long long int n, unsigned int base,
		char *digits, long long int *printcount)
{
	if (n >= base)
		printbasenbr(n / base, base, digits, printcount);
	printchar(digits[n % base], printcount);
}
