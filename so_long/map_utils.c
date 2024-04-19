/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:34:24 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/15 11:33:27 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	str_count_char(char *line, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!line)
		return (count);
	while (line[i])
	{
		if (line[i] == c)
			count++;
		i++;
	}
	return (count);
}

static void	init_matrix_rows(int fd, t_game *data)
{
	int		i;
	char	*line;

	i = 0;
	while (i < data->map.height)
	{
		line = get_next_line(fd);
		if (ft_strchr(line, '\n'))
			data->map.matrix[i] = ft_substr(line, 0, (int)ft_strlen(line) - 1);
		else
			data->map.matrix[i] = ft_substr(line, 0, (int)ft_strlen(line));
		if (!data->map.matrix[i])
		{
			close(fd);
			free_matrix(data->map.matrix);
			perror("Error\nCould not allocate sufficient memory");
			exit(1);
		}
		ft_free(line);
		i++;
	}
}

void	init_matrix(char *path, t_game *data)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nError opening file");
		exit(1);
	}
	data->map.matrix = malloc((data->map.height + 1) * sizeof(char *));
	if (!data->map.matrix)
	{
		close(fd);
		perror("Error\nCould not allocate sufficient memory");
		exit(1);
	}
	data->map.matrix[data->map.height] = NULL;
	init_matrix_rows(fd, data);
	close(fd);
}
