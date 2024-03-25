#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	data;
	
	check_args(argc, argv);
	init_map(argv[1], &data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, data.map.width * PIXELS_PER_UNIT, data.map.height * PIXELS_PER_UNIT, "GAME_TITLE");
	if (!data.win)
		return (mlx_destroy_display(data.mlx), free(data.mlx), 1);
	init_graphics();
	update_screen(&data);
	mlx_key_hook(data.win, handle_input, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
