/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:43:26 by mpalacin          #+#    #+#             */
/*   Updated: 2024/01/18 17:00:49 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*strmapi;
	unsigned int	i;

	strmapi = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!strmapi)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		strmapi[i] = (*f)(i, s[i]);
		i++;
	}
	strmapi[i] = '\0';
	return (strmapi);
}
