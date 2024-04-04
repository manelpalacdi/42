/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:33:42 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/04 13:09:59 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_image(char *path, int x, int y, t_game *data)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(data->mlx, path, &width, &height);
	if (!img)
		return ;
	mlx_put_image_to_window(data->mlx, data->win,
		img, x * PIXELS_PER_UNIT, y * PIXELS_PER_UNIT);
	mlx_destroy_image(data->mlx, img);
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
				draw_image("textures/0.xpm", j, i, data);
			else if (data->map.matrix[i][j] == '1')
				draw_image("textures/1.xpm", j, i, data);
			else if (data->map.matrix[i][j] == 'C')
				draw_image("textures/C.xpm", j, i, data);
			else if (data->map.matrix[i][j] == 'E')
				draw_image("textures/E.xpm", j, i, data);
			else if (data->map.matrix[i][j] == 'P')
				draw_image("textures/P.xpm", j, i, data);
			j++;
		}
		j = 0;
		i++;
	}
}
