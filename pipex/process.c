/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:47:32 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/30 12:47:33 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fork_execute(int in, int out, const char *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit_error("fork error");
	if (pid == 0)
	{
		if (in != 0)
		{
			dup2(in,  0);
			close(in);
		}
		if (out != 1)
		{
			dup2(out, 1);
			close(out);
		}
		return (execve(cmd, cmd, NULL));
	}
	else
	{
		return (pid);
	}
}
