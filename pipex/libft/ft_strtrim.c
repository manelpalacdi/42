/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:32:58 by mpalacin          #+#    #+#             */
/*   Updated: 2024/01/24 12:36:39 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*strtrim;
	unsigned int	i;
	size_t			len;

	i = 0;
	len = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (len > i && ft_strchr(set, s1[len - 1]))
		len--;
	strtrim = ft_substr(s1, i, len - i);
	if (!strtrim)
		return (NULL);
	return (strtrim);
}
