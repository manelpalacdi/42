/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:34:43 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/04 12:41:10 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"
# define PIXELS_PER_UNIT 64

typedef struct s_map
{
	char	**matrix;
	int		width;
	int		height;
	int		collectables;
}	t_map;
typedef struct s_player
{
	int	x;
	int	y;
	int	collected;
	int	can_move;
	int	move_count;
}	t_player;
typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
}	t_game;
int		handle_input(int keysym, t_game *data);
int		close_window(t_game *data);
char	*get_next_line(int fd);
void	check_args(int argc, char **argv);
void	check_matrix(t_game *data);
void	init_map(char *path, t_game *data);
void	init_matrix(char *path, t_game *data);
int		str_count_char(char *line, char c);
int		check_valid_route(t_game *data);
void	flood_algorithm(t_game *data, int x, int y, char **visited, int *ccount);
void	update_screen(t_game *data);
void	move_to(t_game *data, int x, int y);
void	stop_movement(t_game *data);
void	start_movement(t_game *data);
void	mlx_free_exit_all(t_game *data);
void	free_matrix(char **matrix);
void	ft_free(void *var);
#endif
