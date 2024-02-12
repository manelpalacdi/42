/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:06:01 by mpalacin          #+#    #+#             */
/*   Updated: 2024/02/12 13:23:27 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_handle_remainder(char *buf_line, char *next_line)
{
	char	*remainder;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(buf_line);
	while (buf_line[i] != '\n' && buf_line[i] != '\0')
	{
		i++;
	}
	next_line = malloc(i + 2);
	if (!next_line)
		return (NULL);
	next_line[i] = '\n';
	next_line[i + 1] = '\0';
	if (!ft_memmove(next_line, buf_line, i))
		return (NULL);
	remainder = malloc(len - i);
	if (!remainder)
		return (NULL);
	remainder[len - i] = '\0';
	if (!ft_memmove(remainder, buf_line + i + 1, len - i))
		return (NULL);
	free(buf_line);
	return (remainder);
}

static char	*_join_buf(char *line, char *buf)
{
	char	*joined;
	size_t	i;
	size_t	line_len;
	size_t	buf_len;

	i = 0;
	line_len = ft_strlen(line);
	buf_len = ft_strlen(buf);
	joined = malloc(line_len + buf_len + 1);
	if (!joined)
		return (NULL);
	while (i < line_len)
	{
		joined[i] = line[i];
		i++;
	}
	i = 0;
	while (i < buf_len)
	{
		joined[line_len + i] = buf[i];
		i++;
	}
	joined[line_len + buf_len] = '\0';
	free(line);
	return (joined);
}

static char	*_buf_to_line(int fd)
{
	char	*buf;
	char	*line;
	int		read_bytes;

	line = NULL;
	while (!ft_strchr(line, '\n'))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == 0)
		{
			free(buf);
			return (line);
		}
		line = _join_buf(line, buf);
		free(buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf_line;
	char		*next_line;

	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, next_line, 0) < 0)
		return (NULL);
	buf_line = _buf_to_line(fd);
	if (!buf_line)
		return (NULL);
	buf_line = _handle_remainder(buf_line, next_line);
	if (!buf_line)
		return (NULL);
	return (next_line);
}
