/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:34:35 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/04 11:57:20 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *data, int x, int y)
{
	char	*moves;

	data->map.matrix[data->player.x][data->player.y] = '0';
	data->player.x = x;
	data->player.y = y;
	data->map.matrix[data->player.x][data->player.y] = 'P';
	data->player.move_count++;
	write(1, "Total moves: ", 13);
	moves = ft_itoa(data->player.move_count);
	write(1, moves, ft_strlen(moves));
	ft_free(moves);
	write(1, "\n", 1);
}

void	stop_movement(t_game *data)
{
	data->player.can_move = 0;
	data->player.move_count = 0;
}

void	start_movement(t_game *data)
{
	data->player.can_move = 1;
	data->player.move_count = 0;
}

void	do_position_action(t_game *data, int x, int y, char action)
{
	if (action == '1')
		return ;
	else if (action == '0')
		move_player(data, x, y);
	else if (action == 'C')
	{
		data->player.collected += 1;
		move_player(data, x, y);
	}
	else if (action == 'E')
	{
		if (data->player.collected == data->map.collectables)
		{
			write(1, "YOU WON!\n", 9);
			move_player(data, x, y);
			stop_movement(data);
		}
		else
			write(1, "Can't exit yet, there are coins left!\n", 38);
	}
}

void	move_to(t_game *data, int x, int y)
{
	if (data->player.can_move)
	{
		do_position_action(data, x, y, data->map.matrix[x][y]);
		update_screen(data);
	}
}
