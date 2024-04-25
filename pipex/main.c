/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:33:38 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/25 13:04:14 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_script(char **argv)
{
	int	fd;

	if (access(SHNAME, F_OK) == 0)
		exit_error("script.sh already exists");
	fd = open(SHNAME, O_CREAT | O_WRONLY, S_IRWXU);
	printf("%d\n", fd);
	if (fd < 0)
		exit_error("Could not create script");
	ft_putendl_fd("#!/bin/bash", fd);
	ft_putchar_fd('<', fd);
	ft_putstr_fd(argv[0], fd);
	ft_putchar_fd(' ', fd);
	ft_putstr_fd(argv[1], fd);
	ft_putstr_fd(" | ", fd);
	ft_putstr_fd(argv[2], fd);
	ft_putstr_fd(" >", fd);
	ft_putstr_fd(argv[3], fd);
	close(fd);
}

int	main(int argc, char **argv)
{
	char	*newarg[] = { SHNAME, NULL };
	char	*newenv[] = { NULL };
	if (argc != 5)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	create_script(argv + 1);
	execve(SHNAME, newarg, newenv);
	exit_error("Execve error");
	return (0);
}

vim pipe()
{
	pipe()-> para hacer una tuberia que conecte los subprocesos
	fork()--> te crea un subproceso
	dup2(fd, 0);--> si es 0 es stdin, si es 1 es stdout
	dup2(fd, 0)--> hace que lo que haya en fd sea el input
	dup2(fd, 1)--> hace que el resultado se escriba en el fd
	Tienes de cerrar el otro extremo de la tuberia.
}
