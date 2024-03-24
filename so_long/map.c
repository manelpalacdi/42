#include "so_long.h"

void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("Too many arguments");
                exit(1);
	}
	if (ft_strlen(ft_strchr(argv[1], '.')) != 4
                        || ft_memcmp(ft_strchr(argv[1], '.'), ".ber", 4) != 0)
	{
		perror("Incorrect map extension, enter .ber file");
                exit(1);
	}
}

void	init_matrix(char *path, t_game *data)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(path);
		perror("Error opening file");
		exit(1);
	}
	data.map.matrix = malloc(data.map.height);
	if (!data.map.matrix)
	{
		free(path);
		perror("Could not allocate sufficient memory");
		exit(1);
	}
	while (i < data.map.height)
	{
		data.map.matrix[i] = get_next_line(fd);
		if (!data.map.matrix[i])
		{
			free(path);
			free_matrix(data.map.matrix, i);
			perror("Could not allocate sufficient memory");
			exit(1);
		}
		i++;
	}
	close(fd);
}

void	check_matrix(t_game *data)
{
	if (check_rectangular_map(data) || check_closed_map(data) || check_value_map(data) || check_valid_route(data))
	{
		free_matrix(data.map.matrix, data.map.height);
		perror("Map has incorrect format");
		exit(1);
	}
}

int	check_rectangular_map(t_game *data)
{
	int	i;

	i = 0;
	while (i < data.map.height)
	{
		if (ft_strlen(data.map.matrix[i]) != data.map.width)
			return (1);
		i++;
	}
	return (0);
}

int	check_closed_map(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data.map.height)
	{
		while (j < data.map.width)
		{
			if (i == 0 || i == data.map.height - 1)
			{
				if (data.map.matrix[i][j] != 1)
					return (1);
			}
			else
			{
				if (data.map.matrix[i][0] != 1 || data.map.matrix[i][data.map.width - 1] != 1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_value_map(t_game *data)
{
	int	i;
	int	j;
	int	pcount;
	int	ecount;
	int	ccount;

	i = 0;
	j = 0;
	pcount = 0;
	ecount = 0;
	ccount = 0;
	while (i < data.map.height)
	{
		while (j < data.map.width)
		{
			if (data.map.matrix[i][j] == 'P')
				pcount++;
			if (data.map.matrix[i][j] == 'E')
				ecount++;
			if (data.map.matrix[i][j] == 'C')
				ccount++;
			j++;
		}
		i++;
	}
	if (!pcount || pcount > 1 || !ecount || ecount > 1 || !ccount)
		return (1);
	return (0);
}

int	check_valid_route(t_game *data, int last_x, int last_y)
{
	int	**visited;
	int	ccount;

	visited = ft_calloc(data.map.height, sizeof(int));
	if (!visited)
	{
		perror("Could not allocate sufficient memory");
		exit(1);
	}
	while (i < data.map.height)
	{
		visited[i] = ft_calloc(data.map.width, sizeof(int));
		if (!visited[i])
		{
			free_matrix(visited, i);
			perror("Could not allocate sufficient memory");
			exit(1);
		}
		i++;
	}
	flood_algorithm(data, data.player.x, data.player.y, visited, &ccount);
	free_matrix(visited, data.map.height);
	if (ccount != data.map.collectables)
		return (1);
	return (0);

}

void	init_map(char *name, t_game *data)
{
	char	*path;

	path = ft_strjoin("/maps/", name);
	if (!path)
	{
		perror("Could not allocate sufficient memory");
		exit(1);
	}
	init_map_properties(path, data);
	ft_free(path);
	init_player_pos(data);
	check_matrix(data);
}

void	init_map_properties(char *path, t_game *data)
{
	int	fd;
	char	*line;

        fd = open(path, O_RDONLY);
        data.map.height = 0;
	if (fd == -1)
	{
		free(path);
		perror("Could not open map path file");
		exit(1);
	}
        line = get_next_line(fd);
	data.map.collectables += str_count_char(line, 'C');
	data.map.width = ft_strlen(line);
        while (line)
        {
		ft_free(line);
		line = get_next_line(fd);
		data.map.collectables += str_count_char(line, 'C');
		data.map.height += 1;
	}
	init_matrix(path, data);
	close(fd);
}

void	init_player_pos(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data.map.height)
	{
		while (j < ft_strlen(data.map.matrix[i]))
		{
			if (data.map.matrix[i][j] == 'P')
			{
				data.player.x = i;
				data.player.y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

/*
int	read_line(char *line, char **matrix, int x, int y)
{
	int	x;

	x = 0;
	while(line[i])
	{
		if (line[i] == '0')
			data.map.matrix[x][y] = '0';
			draw_image("/textures/0.xpm", x, y, data);
		else if (line[i] == '1')
			data.map.matrix[x][y] = '1';
			draw_image("/textures/1.xpm", x, y, data);
		else if (line[i] == 'C')
			data.map.matrix[x][y] = 'C';
			draw_image("/textures/C.xpm", x, y, data);
		else if (line[i] == 'E')
			data.map.matrix[x][y] = 'E';
			draw_image("/textures/E.xpm", x, y, data);
		else if (line[i] == 'P')
			data.map.matrix[x][y] = 'P';
			data.player.x = x;
			data.player.y = y;
			draw_image("/textures/P.xpm", x, y, data);
		else
			return (write(2, "Error\n", 6), 1);
	}
	return (0);
}
*/
