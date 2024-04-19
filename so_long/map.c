/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:34:19 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/15 11:27:38 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("Error\nToo many arguments");
		exit(1);
	}
	if (ft_strlen(ft_strchr(argv[1], '.')) != 4
		|| ft_memcmp(ft_strchr(argv[1], '.'), ".ber", 4) != 0)
	{
		perror("Error\nIncorrect map extension, enter .ber file");
		exit(1);
	}
}

void	init_map_properties(char *path, t_game *data)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nCould not open map path file");
		exit(1);
	}
	data->map.height = 0;
	data->map.collectables = 0;
	line = get_next_line(fd);
	data->map.collectables += str_count_char(line, 'C');
	data->map.width = (int)ft_strlen(line) - 1;
	while (line)
	{
		ft_free(line);
		line = get_next_line(fd);
		data->map.collectables += str_count_char(line, 'C');
		data->map.height += 1;
	}
	close(fd);
}

void	init_player_pos(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map.height)
	{
		while (j < (int)ft_strlen(data->map.matrix[i]))
		{
			if (data->map.matrix[i][j] == 'P')
			{
				data->player.x = i;
				data->player.y = j;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_map(char *path, t_game *data)
{
	init_map_properties(path, data);
	init_matrix(path, data);
	init_player_pos(data);
	check_matrix(data);
}
