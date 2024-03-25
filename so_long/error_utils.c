#include "so_long.h"

void	mlx_free_exit_all(t_game *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1);
}

void	free_matrix(void **matrix, int max_row)
{
	int	i;

	i = 0;
	while (i < max_row)
	{
		ft_free(matrix[i]);
		i++;
	}
	ft_free(matrix);
}

void	ft_free(void *var)
{
	if (var)
		free(var);
}
