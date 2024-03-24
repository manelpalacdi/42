#include "so_long.h"

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	if (keysym == XK_w)
	{
		if (data.map.matrix[data.player.x][data.player.y + 1] != '1')
			move_to(data, data.player.x, data.player.y + 1);
	}
	if (keysym == XK_a)
	{
		if (data.map.matrix[data.player.x - 1][data.player.y] != '1')
			move_to(data, data.player.x - 1, data.player.y);
	}
	if (keysym == XK_s)
	{
		if (data.map.matrix[data.player.x][data.player.y - 1] != '1')
			move_to(data, data.player.x, data.player.y - 1);
	}
	if (keysym == XK_d)
	{
		if (data.map.matrix[data.player.x + 1][data.player.y] != '1')
			move_to(data, data.player.x + 1, data.player.y);
	}
	return (0);
}

