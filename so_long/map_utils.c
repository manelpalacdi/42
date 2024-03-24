#include "so_long.h"

int	str_count_char(char *line, char c)
{
	int	i;
	int	count;

	i = 0;
	count++;
	while (line[i])
	{
		if (line[i] == c)
			count++;
	}
	return (count);
}

void	flood_algorithm(t_game *data, int x, int y, int **visited, int *ccount)
{	
	if (visited[x][y] || data.map.matrix[x][y] == '1')
		return ;
	visited[x][y] = 1;
	if (data.map.matrix[x][y] == 'C')
		*ccount += 1;
	flood_algorithm(data, x, y + 1, visited);
	flood_algorithm(data, x + 1, y, visited);
	flood_algorithm(data, x, y - 1, visited);
	flood_algorithm(data, x - 1, y, visited);
	return ;
}
