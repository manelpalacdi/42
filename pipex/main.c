/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:33:38 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/07 12:54:31 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int		p[2];
	int		in;
	int		i;

	if (argc != 5)
	{
		write(1, "Wrong number of arguments\n", 26);
		return (1);
	}
	i = 1;
	while (i <= argc)
	{
		if (pipe(p) < 0)
			exit_error("pipe error");
		if (i == 1)
		{
			check_input_file(argv[i]);
			if (fork_execute(0, p[1], (const char *)get_input(argv[i])) < 0)
				exit_error("execve error");
			close(p[1]);
			in = p[0];
		}
		else if (i == argc)
		{
			check_output_file(argv[i]);
			if (fork_execute(in, p[1], (const char *)get_output(argv[i])) < 0)
				exit_error("execve error");
			close(p[1]);
			close(p[0]);
			close(in);
		}
		else
		{
			if (fork_execute(in, p[1], argv[i]) < 0)
				exit_error("execve error");
			close(p[1]);
			in = p[0];
		}
		i++;
	}
	return (0);
}
