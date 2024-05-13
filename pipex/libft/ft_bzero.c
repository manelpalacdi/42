/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:47:13 by mpalacin          #+#    #+#             */
/*   Updated: 2024/01/15 16:36:07 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <string.h>*/

void	ft_bzero(void *s, size_t n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return ;
	while (count < n)
	{
		((char *)s)[count] = 0;
		count++;
	}
	return ;
}
/*
int	main(int argc, char **argv)
{
	ft_bzero(argv[1], 4);
	printf("%s\n", argv[1]);
}*/
