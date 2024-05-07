/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:20:49 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/07 12:51:58 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_output(const char *arg)
{
	char	*str;

	str = ft_strjoin(arg, " >");
	if (!str)
		exit_error("memory problems");
	return (str);
}

void	check_output_file(const char *out)
{
	if (access(out, F_OK) < 0)
	{
		ft_printf("no such file or directory: %s\n", out);
		exit(1);
	}
	if (access(out, W_OK) < 0)
	{
		ft_printf("permission denied: %s\n", out);
		exit(1);
	}
}
