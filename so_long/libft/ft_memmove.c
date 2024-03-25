/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:59:50 by mpalacin          #+#    #+#             */
/*   Updated: 2024/01/23 16:28:44 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < len)
	{
		if (s < d)
			d[len - i - 1] = s[len - i - 1];
		else
			d[i] = s[i];
		i++;
	}
	return (dst);
}
/*
int	main(void)
{
	char	src[] = "hola";
	char	*dst;

	dst = malloc(sizeof(char) * 10);
	printf("%s\n", ft_memmove((void *)dst, (const void *)src, 2));
}*/
