/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:59:41 by mpalacin          #+#    #+#             */
/*   Updated: 2024/02/05 12:55:03 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	char	*str;
	int		a;

	str = "%p %p\n";
	printf("GOT:\n");
	printf("%d\n", ft_printf(str, LONG_MIN, LONG_MAX));
	printf("\nEXPECTED:\n");
	printf("%d\n", printf(str, LONG_MIN, LONG_MAX));
	printf("\nNEXT TEST:\n");
	str = "%c\n%d\n%i\n%u\n%x\n%X\n%s\n%p\n";
	printf("GOT:\n");
	printf("%d\n", ft_printf(str, 'o', -1, 22, 432, 15, 15, "hola", &a));
	printf("\nEXPECTED:\n");
	printf("%d\n", printf(str, 'o', -1, 22, 432, 15, 15, "hola", &a));
	str = "%s\n";
	printf("\nGOT:\n");
	printf("%d\n", ft_printf(str, "hola"));
	printf("\nEXPECTED:\n");
	printf("%d\n", printf(str, "hola"));
	str = "%s\n";
	printf("\nGOT:\n");
	printf("%d\n", ft_printf(str, NULL));
	printf("\nEXPECTED:\n");
	printf("%d\n", printf(str, NULL));
	str = "\001\002\007\v\010\f\r\n";
	printf("\nGOT:\n");
	printf("%d\n", ft_printf("\001\002\007\v\010\f\r\n"));
	printf("\nEXPECTED:\n");
	printf("%d\n", printf("\001\002\007\v\010\f\r\n"));
}
