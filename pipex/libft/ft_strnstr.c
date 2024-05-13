/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:22:07 by mpalacin          #+#    #+#             */
/*   Updated: 2024/01/23 17:21:05 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (!haystack[i + j] && needle[j] == '\0')
				return ((char *)(haystack + i));
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		j = 0;
		i++;
	}
	return (NULL);
}
/*{
	size_t	i;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	if ((int)len - (int)ft_strlen(needle) <= 0)
		return (NULL);
	while (haystack[i] && i < len - ft_strlen(needle))
	{
		if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}*/
