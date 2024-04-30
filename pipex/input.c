/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:07:27 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/30 12:47:29 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_input(const char *in, int out)
{
	int	fd;

	if (access(in, R_OK) < 0)
	{
		ft_printf("permission denied: %s\n", in);
		exit(1);
	}
	fd = open(in, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("no such file or directory: %s\n", in);
		exit(1);
	}
	read_bytes(
	close(fd);
}
