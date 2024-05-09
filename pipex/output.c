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

void	check_output_file(const char *out)
{
	if (access(out, F_OK) < 0)
        return ;
    else
    {
        if (access(out, W_OK) < 0)
        {
            ft_putstr_fd("pipex: permission denied: ", 2);
            ft_putstr_fd((char *)out, 2);
            exit(1);
        }
    }
}   
