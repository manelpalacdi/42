/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:23:32 by mpalacin          #+#    #+#             */
/*   Updated: 2024/03/28 12:20:11 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_get_remainder(char *buf_line)
{
	char	*remainder;
	size_t	i;
	size_t	len;

	i = 0;
	len = gnl_strlen(buf_line);
	while (buf_line[i] && buf_line[i] != '\n')
		i++;
	if (i == len)
	{
		gnl_free(buf_line);
		return (NULL);
	}
	remainder = gnl_substr(buf_line, i + 1, len - i - 1);
	gnl_free(buf_line);
	return (remainder);
}

static char	*_malloc_next_line(char *buf_line, size_t len)
{
	char	*next_line;
	size_t	i;

	i = 0;
	if (buf_line[len] == '\0')
	{
		next_line = malloc(len + 1);
		if (!next_line)
			return (NULL);
		next_line[len] = '\0';
	}
	else
	{
		next_line = malloc(len + 2);
		if (!next_line)
			return (NULL);
		next_line[len] = '\n';
		next_line[len + 1] = '\0';
	}
	return (next_line);
}

static char	*_get_line(char *buf_line)
{
	char	*next_line;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (buf_line[0] == '\0')
		return (NULL);
	while (buf_line[len] && buf_line[len] != '\n')
		len++;
	next_line = _malloc_next_line(buf_line, len);
	if (!next_line)
		return (NULL);
	while (i < len)
	{
		next_line[i] = buf_line[i];
		i++;
	}
	return (next_line);
}

static char	*_read_line(int fd, char *buf_line)
{
	char	*buf;
	int		read_bytes;

	while (!gnl_strchr(buf_line, '\n'))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (gnl_free(buf_line), NULL);
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (gnl_free(buf), gnl_free(buf_line), NULL);
		buf[read_bytes] = '\0';
		buf_line = gnl_strjoinfree(buf_line, buf);
		gnl_free(buf);
		if (!buf_line)
			return (NULL);
		if (read_bytes == 0)
			break ;
	}
	return (buf_line);
}

char	*get_next_line(int fd)
{
	static char	*buf_line = NULL;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf_line = _read_line(fd, buf_line);
	if (!buf_line)
		return (NULL);
	next_line = _get_line(buf_line);
	if (!next_line && buf_line[0])
	{
		gnl_free(buf_line);
		buf_line = NULL;
		return (NULL);
	}
	buf_line = _get_remainder(buf_line);
	return (next_line);
}
