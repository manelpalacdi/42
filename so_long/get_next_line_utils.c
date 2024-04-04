/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:24:06 by mpalacin          #+#    #+#             */
/*   Updated: 2024/03/26 13:02:48 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	len = gnl_strlen(s);
	while (i < len + 1)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > gnl_strlen(s))
		len = 0;
	else if (gnl_strlen(s + start) < len)
		len = gnl_strlen(s + start);
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

void	gnl_free(char *s)
{
	if (s)
		free(s);
}

char	*gnl_strjoinfree(char *line, char *buf)
{
	char	*str;
	size_t	i;
	size_t	line_len;
	size_t	buf_len;

	i = 0;
	line_len = gnl_strlen(line);
	buf_len = gnl_strlen(buf);
	str = malloc(line_len + buf_len + 1);
	if (!str)
		return (gnl_free(line), NULL);
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
	return (gnl_free(line), str);
}
