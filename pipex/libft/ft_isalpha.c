/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:10:18 by mpalacin          #+#    #+#             */
/*   Updated: 2024/01/11 15:34:24 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
#include <ctype.h>*/

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
/*
int	main(int argc, char **argv)
{
	printf("%d\n", ft_isalpha(argv[1][0]));
	printf("%d\n", isalpha(argv[1][0]));
}*/
