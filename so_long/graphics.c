#include "so_long.h"

void	draw_image(char *path, int x, int y, t_game *data)
{
	void	*img;
	int	width;
	int	height;
	
	if (x > data->map.width || y > data->map.height)
		return ;
	img = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	if (!img)
		return ;
	mlx_put_image_to_window(data->mlx, data->win, data->graphics.img, x * PIXELS_PER_UNIT, y * PIXELS_PER_UNIT);
}

void	update_screen(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map.height)
	{
		while (j < data->map.width)
		{
			if (data->map.matrix[i][j] == '0')
				draw_image("/textures/0.xpm", i, j, data);
			else if (data->map.matrix[i][j] == '1')
				draw_image("/textures/1.xpm", i, j, data);
			else if (data->map.matrix[i][j] == 'C')
				draw_image("/textures/C.xpm", i, j, data);
			else if (data->map.matrix[i][j] == 'E')
				draw_image("/textures/E.xpm", i, j, data);
			else if (data->map.matrix[i][j] == 'P')
				draw_image("/textures/P.xpm", i, j, data);
		}
	}
}

void	init_graphics(t_game *data)
{
	data->graphics.img = mlx_new_image(data->mlx, data->map.width * PIXELS_PER_UNIT, data->map.height * PIXELS_PER_UNIT);
        data->graphics.img_pixels = mlx_get_data_addr(data->graphics.img,
                        &(data->graphics.bits_per_pixel),
                        &(data->graphics.line_len),
                        &(data->graphics.endian));
}
