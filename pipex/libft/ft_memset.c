/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:41:17 by mpalacin          #+#    #+#             */
/*   Updated: 2024/01/11 16:21:26 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <string.h>
#include <stdlib.h>*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	count;

	count = 0;
	while (count < len)
	{
		((char *)b)[count] = c;
		count++;
	}
	return (b);
}
/*
int	main(int argc, char **argv)
{
	printf("%s\n", ft_memset(argv[1], 'c', 4));
	printf("%s\n", memset(argv[1], 'c', 4));
}*/
