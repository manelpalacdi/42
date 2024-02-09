/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:23:12 by mpalacin          #+#    #+#             */
/*   Updated: 2024/02/08 11:41:27 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_lINE

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 10

typedef struct s_list
{
	char			*buf;
	struct s_list	*next;
}	t_list;
char	*get_next_line(int fd);

#endif
