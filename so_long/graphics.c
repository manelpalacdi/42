#include "so_long.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(img->img_pixels_ptr + offset)) = color;
}

void	draw_image(char *path, int x, int y, t_game *data)
{
	void	*img;
	int	width;
	int	height;
	
	if (x > data->map.width | y > data->map.height)
		return ;
	img = mlx_xpm_file_to_image(data.mlx, path, &width, &height);
	if (!img)
		return ;
	mlx_put_image_to_window(data->mlx, data->win, data->graphics.img, x, y);
}

void	init_graphics(t_game *data)
{
	data.graphics.img = mlx_new_image(data.mlx, 420, 270);
        data.graphics.img_pixels = mlx_get_data_addr(data.graphics.img,
                        &data.graphics.bits_per_pixel,
                        &data.graphics.line_len,
                        &data.graphics.endian);
}
