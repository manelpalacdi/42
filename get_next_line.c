/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:06:01 by mpalacin          #+#    #+#             */
/*   Updated: 2024/02/08 12:55:31 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void _handle_remainder(t_list *node)
{
	char	*line;
	size_t	len;

	len = 0;
	while (node 
}

static int	_read_to_node(t_list **node, int fd, int *found_nl)
{
	read_bytes = read(fd, (*node)->buf, BUFFER_SIZE);
	if (read_bytes < 0)
		return (0);
	if (read_bytes == 0)
	{
		found_nl = 1;
		(*node)->next = NULL;
	}
	(*node)->buf[read_bytes] = '\0';
	if (ft_strchr(*node->buf, '\n'))
	{
		found_nl = 1;
		(*node)->next = NULL;
	}
	else
		(*node)->next = ft_lstnew(*node);
		if ((*node)->next)
			*node = (*node)->next;
}

static int	_read_to_list(t_list *node, int fd)
{
	int		found_nl;
	int		read_bytes;

	found_nl = 0;
	node->buf = malloc(BUFFER_SIZE + 1);
	if (!node->buf)
		return (NULL);
	if (read(fd, *node->buf, 0) < 0)
	{
		free(node->buf);
		return (NULL);
	}
	while (!found_nl)
	{
		if(_read_to_node(&node, fd, &found_nl) < 0)
			return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*node;
	t_list			*first_node;
	char			*line;
	if (fd < 0)
		return (NULL);
	if (!node)
	{
		node = ft_lstnew(NULL);
		if (!node)
			return (NULL);
	}
	first_node = node;
	if (!_read_to_list(node, fd))
	{
		ft_lstclear(&node);
		return (NULL);
	}
	line = _join_node_content(node);
	_handle_remainder(line);
	free(line);
	ft_lstclear(first_node);
}
