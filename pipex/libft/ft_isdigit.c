/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:16:12 by mpalacin          #+#    #+#             */
/*   Updated: 2024/01/12 13:13:44 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <ctype.h>*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
int	main(int argc, char **argv)
{
	printf("%d\n", ft_isdigit(argv[1][0]));
	printf("%d\n", isdigit(argv[1][0]));
}*/
