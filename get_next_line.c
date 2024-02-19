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

static char	*_get_remainder(char *buf_line)
{
	char	*remainder;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!buf_line || !buf_line[0])
		return ("");
	i = 0;
	j = 0;
	len = ft_strlen(buf_line);
	while (buf_line[i] && buf_line[i] != '\n')
		i++;
	if (i == len)
		return ("");
	len = len - i;
	remainder = malloc(len);
	if (!remainder)
		return ("");
	while (j < len)
	{
		remainder[j] = buf_line[i + 1];
		i++;
		j++;
	}
	free(buf_line);
	return (remainder);
}

static char	*_get_line(char *buf_line)
{
	char	*next_line;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!buf_line[0])
		return ("");
	while (buf_line[i] && buf_line[i] != '\n')
		len++;
	next_line = malloc(len + 2);
	if (!next_line)
		return (NULL);
	while (i < len)
	{
		next_line[i] = buf_line[i];
		i++;
	}
	next_line[i] = '\n';
	next_line[i + 1] = '\0';
	return (next_line);
}

static char	*_read_line(int fd, char *buf_line)
{
	char	*buf;
	int	read_bytes;

	while (!ft_strchr(buf_line, '\n'))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		read_bytes = read(fd, buf, BUFFER_SIZE);
		buf[read_bytes] = '\0';
		buf_line = ft_strjoinfree(buf_line, buf);
		if (!buf_line)
			return (NULL);
		free(buf);
		if (read_bytes == 0)
			break ;
	}
	return (buf_line);
}

char	*get_next_line(int fd)
{
	static char	*buf_line;
	char		*next_line;

	if (fd < 0 || read(fd, buf, 0) == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buf_line = _read_line(fd, buf_line);
	next_line = _get_line(buf_line);
	buf_line = _get_remainder(buf_line);
	return (next_line);
}
