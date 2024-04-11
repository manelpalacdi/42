/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:34:24 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/04 12:45:36 by mpalacin         ###   ########.fr       */
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
	int	i;
	char *line;

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

void	flood_algorithm(t_game *data, int x, int y, char **visited, int *ccount)
{	
	if (visited[x][y] || data->map.matrix[x][y] == '1')
		return ;
	visited[x][y] = '1';
	if (data->map.matrix[x][y] == 'C')
		*ccount += 1;
	flood_algorithm(data, x, y + 1, visited, ccount);
	flood_algorithm(data, x + 1, y, visited, ccount);
	flood_algorithm(data, x, y - 1, visited, ccount);
	flood_algorithm(data, x - 1, y, visited, ccount);
	return ;
}

int	check_valid_route(t_game *data)
{
	int		i;
	char	**visited;
	int		ccount;

	i = 0;
	ccount = 0;
	visited = ft_calloc(data->map.height + 1, sizeof(char *));
	if (!visited)
	{
		free_matrix(data->map.matrix);
		perror("Error\nCould not allocate sufficient memory");
		exit(1);
	}
	while (i < data->map.height)
	{
		visited[i] = ft_calloc(data->map.width + 1, sizeof(char));
		if (!visited[i])
		{
			free_matrix(data->map.matrix);
			free_matrix(visited);
			perror("Error\nCould not allocate sufficient memory");
			exit(1);
		}
		i++;
	}
	flood_algorithm(data, data->player.x, data->player.y, visited, &ccount);
	free_matrix(visited);
	if (ccount != data->map.collectables)
		return (1);
	return (0);
}
