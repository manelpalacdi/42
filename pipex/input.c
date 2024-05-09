/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:07:27 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/07 12:54:28 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_input_file(const char *in)
{
	if (access(in, F_OK) < 0)
	{
		ft_printf("no such file or directory: %s\n", in);
		exit(1);
	}
	if (access(in, R_OK) < 0)
	{
		ft_printf("permission denied: %s\n", in);
		exit(1);
	}
}
