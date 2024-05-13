/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:47:32 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/13 12:32:01 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int execute(const char *cmd, char **env)
{
    char    **s_cmd;
    char    *path;

	if (!cmd || cmd[0] == '\0')
    {
        ft_putendl_fd("pipex: enter non void command", 2);
        exit(1);
    }
    s_cmd = ft_split(cmd, ' ');
    path = get_path(s_cmd[0], env);
    if (execve(path, s_cmd, env) < 0)
    {
        ft_putstr_fd("pipex: command not found: ", 2);
        ft_putendl_fd(s_cmd[0], 2);
        free_matrix(s_cmd);
        exit(1);
    }
    return (-1);
}

int	fork_execute(int in, int out, const char *cmd, char **env)
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
		return (execute(cmd, env));
	}
	return (pid);
}

int	fork_execute_in_out(int in, int out, const char *cmd, char **env)
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
		return (execute(cmd, env));
	}
	return (pid);
}
