/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:40:54 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/16 12:09:00 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_args(char **argv, int argc, int *i, int *in)
{
	if (argc < 5)
		exit_error("pipex: wrong number of arguments");
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc < 6)
			exit_error("Wrong number of arguments");
		*i = 2;
		*in = here_doc(argv);
		return (1);
	}
	return (0);
}

void	here_doc_put_in(char **av, int *p)
{
	char	*line;

	close(p[0]);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
		{
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, p[1]);
		free(line);
	}
}

int	here_doc(char **av)
{
	int		p[2];
	pid_t	pid;

	if (pipe(p) < 0)
		exit_error("pipe error");
	pid = fork();
	if (pid == -1)
		exit_error("fork error");
	if (pid == 0)
		here_doc_put_in(av, p);
	else
	{
		close(p[1]);
		dup2(p[0], 0);
		wait(NULL);
	}
	return (p[0]);
}
