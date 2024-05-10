void	here_doc_put_in(char **av, int *p)
{
	char	*line;

	close(p_fd[0]);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
		{
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, p_fd[1]);
		free(line);
	}
}

int here_doc(char **av)
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
