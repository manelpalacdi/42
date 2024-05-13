/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:33:38 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/13 13:53:09 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	handle_input(char **argv, int *p)
{
	int	in;

	check_input_file(argv[1]);
	in = open(argv[1], O_RDONLY);
	if (in < 0)
		exit(1);
	close(p[1]);
	close(p[0]);
	return (in);
}

static int	handle_output(char **argv, int i, int heredoc)
{
	check_output_file(argv[i + 1]);
	if (heredoc)
		out = open(argv[i + 1], O_WRONLY | O_CREAT | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else
		out = open(argv[i + 1], O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (out < 0)
		exit(1);
	return (out);
}

static int	handle_command(char **argv, char **envp, int *p, int in)
{
	if (fork_execute(in, p[1], argv[i], envp) < 0)
		exit_error("execve error");
	close(p[1]);
	return (p[0]);
}

static void	close_all(int *p, int in, int out);
{
	close(p[0]);
	close(p[1]);
	close(in);
	close(out);
}

int	main(int argc, char **argv, char **envp)
{
	int	p[2];
	int	in;
	int	out;
	int	hd;
	int	i;

	i = 1;
	hd = check_args(argv, argc, &i, &in);
	while (i < argc - 1)
	{
		if (pipe(p) < 0)
			exit_error("pipe error");
		if (i == 1)
			in = handle_input(p);
		else if (i == argc - 2)
		{
			if (fork_execute(in, handle_output(argv, i, hd), argv[i], envp) < 0)
				exit_error("execve error");
			close_all(p, in, out);
		}
		else
			in = handle_command(argv, envp, p);
		i++;
	}
	return (0);
}
