/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:51:51 by mpalacin          #+#    #+#             */
/*   Updated: 2024/01/23 16:27:21 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <string.h>*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	count;

	count = 0;
	if (!dst && !src)
		return (NULL);
	while (count < n)
	{
		((char *)dst)[count] = ((char *)src)[count];
		count++;
	}
	return (dst);
}
/*
int	main(int argc, char **argv)
{
	printf("%s\n", ft_memcpy(argv[1], "hola", 3));
	printf("%s\n", memcpy(argv[1], "hola", 3));
}*/
