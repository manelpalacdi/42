#include "so_long.h"

void	move_to(t_game *data, int x, int y)
{
	data.map.matrix[data.player.x][data.player.y] = '0';
	data.player.x = x;
	data.player.y = y;
	do_position_action(data, data.map.matrix[x][y]);
	data.map.matrix[x][y] = 'P';
	update_screen(data);	
}

void	do_position_action(t_game *data, char c)
{
	if (c == 'C')
		data.player.collected += 1;
	if (c == 'E')
	{
		if (data.player.collected == data.map.collectables)
			win_state();
		else
			not_collected_enough();
	}
}
