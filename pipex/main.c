/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:33:38 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/30 12:47:36 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		p[2];
	int		in;
	int		i;

	if (argc != 5)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (pipe(p) < 0)
			exit_error ("pipe error");
		if (fork_execute(in, p[1], argv[i]) < 0)
			exit_error("fork error");
		close(p[1]);
		in = p[0];
		i++;
	}
	pid = fork();
	if (pid < 0)
		exit_error("fork error");
	if (pid == 0)
	{
		if (in != 0)
			dup2(p[0], 0);
		if (execve(argv[i], argv[i], NULL) < 0)
			exit_error("execve error");
	}
	return (0);
}
