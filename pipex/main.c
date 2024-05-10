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

int	main(int argc, char **argv, char **envp)
{
	int		p[2];
	int		in;
    int     out;
	int		i;

	if (argc < 5)
        exit_error("Wrong number of arguments");
    i = 1;
    if (ft_strcmp(argv[1], "here_doc") == 0)
    {
        if (argc < 6)
		    exit_error("Wrong number of arguments");
		i = 3;
		in = here_doc(argv);
	}
	while (i < argc - 1)
	{
		if (pipe(p) < 0)
			exit_error("pipe error");
		if (i == 1)
		{
			check_input_file(argv[i]);
            in = open(argv[i], O_RDONLY);
			close(p[1]);
            close(p[0]);
		}
		else if (i == argc - 2)
		{
			check_output_file(argv[i + 1]);
            out = open(argv[i + 1], O_WRONLY | O_CREAT | O_TRUNC,
                    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			if (fork_execute(in, out, argv[i], envp) < 0)
			    exit_error("execve error");
			close(p[0]);
			close(p[1]);
			close(in);
            close(out);
		}
		else
		{
			if (fork_execute(in, p[1], argv[i], envp) < 0)
				exit_error("execve error");
			close(p[1]);
			in = p[0];
		}
		i++;
	}
	return (0);
}
