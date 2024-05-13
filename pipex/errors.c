/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:46:07 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/25 10:57:15 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_error(const char *error)
{
	size_t	len;

	len = ft_strlen(error);
	write(2, error, len);
	write(2, "\n", 1);
	exit(1);
}
