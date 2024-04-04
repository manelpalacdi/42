/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:33:29 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/04 11:49:29 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_free_exit_all(t_game *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	ft_free(data->mlx);
	exit(1);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		ft_free(matrix[i]);
		i++;
	}
	ft_free(matrix);
}

void	ft_free(void *var)
{
	if (var)
		free(var);
}
