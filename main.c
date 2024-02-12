/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:09:38 by mpalacin          #+#    #+#             */
/*   Updated: 2024/02/12 12:38:47 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		n;
	int		i;
	char	*line;

	n = 1;
	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < n)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
		i++;
	}
}
