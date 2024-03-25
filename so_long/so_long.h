#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# define PIXELS_PER_UNIT 16
typedef struct s_sprite
{
	char	*path;
	int	width;
	int	height;
}	t_sprite;
typedef struct s_img
{
	void	*img;
	char	*img_pixels;
	int	bits_per_pixel;
	int	endian;
	int	line_len;
}	t_img;
typedef struct s_map
{
	char	**matrix;
	int	width;
	int	height;
	int	collectables;
}	t_map;
typedef struct s_player
{
	int	x;
	int	y;
	int	collected;
}	t_player;
typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	graphics;
	t_map	map;
	t_player player;
}	t_game;
int	handle_input(int keysym, t_game *data);
void	check_args(int argc, char **argv);
void	init_map(char *name, t_game *data);
void	init_graphics();
void	update_screen(t_game *data);
void	move_to(t_game *data, int x, int y);
void	mlx_free_exit_all(t_game *data);
void	free_matrix(void **matrix, int max_row);
void	ft_free(void *var);
#endif
