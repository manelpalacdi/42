/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:21:33 by mpalacin          #+#    #+#             */
/*   Updated: 2024/02/12 13:18:30 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (i < len + 1)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoinfree(char *line, char *buf)
{
	char	*str;
	size_t	i;
	size_t	line_len;
	size_t	buf_len;

	i = 0;
	line_len = ft_strlen(line_len);
	buf_len = ft_strlen(buf_len);
	str = malloc(line_len + buf_len + 1);
	if (!str)
		return (NULL);
	while (i < line_len)
	{
		str[i] = line[i];
		i++;
	}
	i = 0;
	while (i < buf_len)
	{
		str[line_len + i] = buf[i];
		i++;
	}
	str[line_len + i] = '\0';
	free(line);
	return (str);
}
