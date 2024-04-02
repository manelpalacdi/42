/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:14:08 by mpalacin          #+#    #+#             */
/*   Updated: 2024/03/07 12:14:17 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*auxlst;
	int		count;

	count = 0;
	auxlst = lst;
	while (auxlst != NULL)
	{
		count++;
		auxlst = auxlst->next;
	}
	return (count);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*auxlst;

	auxlst = *lst;
	while (*lst != NULL)
	{
		*lst = (*lst)->next;
		ft_lstdelone(auxlst, del);
		auxlst = *lst;
	}
	lst = NULL;
}
