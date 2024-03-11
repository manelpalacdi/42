/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:45:55 by mpalacin          #+#    #+#             */
/*   Updated: 2024/02/06 12:04:08 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	_printstr(char *s, long long int *printcount)
{
	if (!s)
	{
		_printstr("(null)", printcount);
		return ;
	}
	while (s[0])
	{
		printchar(s[0], printcount);
		s++;
	}
}

static void	_printconversion(char chr, va_list ptr,
		long long int *printcount)
{
	if (chr == 'c')
		printchar(va_arg(ptr, int), printcount);
	else if (chr == 'd' || chr == 'i')
		printdecimalnbr(va_arg(ptr, int), printcount);
	else if (chr == 'x')
		printbasenbr(va_arg(ptr, unsigned int), 16,
			"0123456789abcdef", printcount);
	else if (chr == 'X')
		printbasenbr(va_arg(ptr, unsigned int), 16,
			"0123456789ABCDEF", printcount);
	else if (chr == 'p')
	{
		_printstr("0x", printcount);
		printbasenbr((unsigned long int)va_arg(ptr, void *),
			16, "0123456789abcdef", printcount);
	}
	else if (chr == 'u')
		printbasenbr(va_arg(ptr, unsigned int), 10, "0123456789",
			printcount);
	else if (chr == 's')
		_printstr(va_arg(ptr, char *), printcount);
	else if (chr == '%')
		printchar('%', printcount);
	else
		*printcount = -1;
}

int	ft_printf(char const *str, ...)
{
	unsigned long int	i;
	long long int		printcount;
	va_list				ptr;

	i = 0;
	printcount = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			_printconversion(str[i], ptr, &printcount);
		}
		else
			printchar(str[i], &printcount);
		i++;
		if (printcount < 0)
			return (-1);
	}
	return (printcount);
}
