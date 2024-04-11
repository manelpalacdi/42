/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:34:05 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/04 13:25:14 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	data;

	check_args(argc, argv);
	init_map(argv[1], &data);
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		free_matrix(data.map.matrix);
		return (1);
	}
	data.win = mlx_new_window(data.mlx,
			data.map.width * PIXELS_PER_UNIT,
			data.map.height * PIXELS_PER_UNIT,
			"SO_LONG");
	if (!data.win)
	{
		free_matrix(data.map.matrix);
		mlx_free_exit_all(&data);
	}
	start_movement(&data);
	update_screen(&data);
	mlx_key_hook(data.win, handle_input, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
}
