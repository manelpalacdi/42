/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:33:55 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/04 13:25:16 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int key, t_game *data)
{
	if (key == 53)
	{
		free_matrix(data->map.matrix);
		mlx_free_exit_all(data);
	}
	if (key == 13)
		move_to(data, data->player.x - 1, data->player.y);
	if (key == 0)
		move_to(data, data->player.x, data->player.y - 1);
	if (key == 1)
		move_to(data, data->player.x + 1, data->player.y);
	if (key == 2)
		move_to(data, data->player.x, data->player.y + 1);
	return (0);
}

int	close_window(t_game *data)
{
	free_matrix(data->map.matrix);
	mlx_free_exit_all(data);
	return (0);
}
