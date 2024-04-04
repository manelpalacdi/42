/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:23:11 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/04 13:25:12 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular_map(t_game *data)
{
	int	i;

	i = 0;
	while (i < data->map.height)
	{
		if ((int)ft_strlen(data->map.matrix[i]) != data->map.width)
			return (1);
		i++;
	}
	return (0);
}

int	check_closed_map(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map.height)
	{
		while (j < data->map.width)
		{
			if (i == 0 || i == data->map.height - 1)
			{
				if (data->map.matrix[i][j] != '1')
					return (1);
			}
			else
			{
				if (data->map.matrix[i][0] != '1' || data->map.matrix[i][data->map.width - 1] != '1')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_value_pec(t_game *data)
{
	int	i;
	int	pcount;
	int	ecount;
	int	ccount;

	i = 0;
	pcount = 0;
	ecount = 0;
	ccount = 0;
	while (i < data->map.height)
	{
		pcount += str_count_char(data->map.matrix[i], 'P');
		ecount += str_count_char(data->map.matrix[i], 'E');
		ccount += str_count_char(data->map.matrix[i], 'C');
		i++;
	}
	if (!pcount || pcount > 1 || !ecount || ecount > 1 || !ccount)
		return (1);
	return (0);
}

int	check_valid_char(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map.height)
	{
		while (j < data->map.width)
		{
			if (data->map.matrix[i][j] != '1' &&
					data->map.matrix[i][j] != '0' &&
					data->map.matrix[i][j] != 'P' &&
					data->map.matrix[i][j] != 'E' &&
					data->map.matrix[i][j] != 'C')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	check_matrix(t_game *data)
{
	if (check_rectangular_map(data) || check_closed_map(data) || check_value_pec(data) || check_valid_char(data) || check_valid_route(data))
	{
		free_matrix(data->map.matrix);
		perror("Error\nMap has incorrect format");
		exit(1);
	}
}
