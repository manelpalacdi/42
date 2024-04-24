/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:33:38 by mpalacin          #+#    #+#             */
/*   Updated: 2024/04/24 12:13:37 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_script(char **argv)
{
	int	fd;

	if (access(SHNAME, F_OK) == 0)
		exit_error("script.sh already exists");
	fd = open(SHNAME, O_CREAT, S_IRWXU);
	if (fd < 0)
		exit_error("Could not create script");
	ft_putendl_fd("#!/bin/bash\n", fd);
	ft_putstr_fd(argv[0], fd);
	ft_putchar_fd(' ', fd);
	ft_putstr_fd(argv[1], fd);
	ft_putchar_fd(' ', fd);
	ft_putstr_fd(argv[2], fd);
	ft_putchar_fd(' ', fd);
	ft_putstr_fd(argv[3], fd);
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc != 5)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	create_script(argv + 1);
	execve(SHNAME, , );
}
