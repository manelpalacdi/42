/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:32:39 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/15 11:52:22 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_algorithm(t_game *data, int x, int y, int *ccount)
{
	if (data->map.visited[x][y] || data->map.matrix[x][y] == '1')
		return ;
	data->map.visited[x][y] = '1';
	if (data->map.matrix[x][y] == 'C')
		*ccount += 1;
	flood_algorithm(data, x, y + 1, ccount);
	flood_algorithm(data, x + 1, y, ccount);
	flood_algorithm(data, x, y - 1, ccount);
	flood_algorithm(data, x - 1, y, ccount);
	return ;
}

void	init_visited(t_game *data)
{
	int		i;

	i = 0;
	data->map.visited = ft_calloc(data->map.height + 1, sizeof(char *));
	if (!data->map.visited)
	{
		free_matrix(data->map.matrix);
		perror("Error\nCould not allocate sufficient memory");
		exit(1);
	}
	while (i < data->map.height)
	{
		data->map.visited[i] = ft_calloc(data->map.width + 1, sizeof(char));
		if (!(data->map.visited[i]))
		{
			free_matrix(data->map.matrix);
			free_matrix(data->map.visited);
			perror("Error\nCould not allocate sufficient memory");
			exit(1);
		}
		i++;
	}
}

int	check_valid_route(t_game *data)
{
	int		i;
	int		ccount;

	i = 0;
	ccount = 0;
	init_visited(data);
	flood_algorithm(data, data->player.x, data->player.y, &ccount);
	free_matrix(data->map.visited);
	if (ccount != data->map.collectables)
		return (1);
	return (0);
}
