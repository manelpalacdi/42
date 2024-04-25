/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:48:58 by mpalacin          #+#    #+#             */
/*   Updated: 2024/01/26 11:59:06 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*auxlst;
	t_list	*firstnode;

	if (!lst)
		return (NULL);
	auxlst = ft_lstnew(lst->content);
	if (!auxlst)
		return (NULL);
	auxlst->content = (*f)(auxlst->content);
	firstnode = auxlst;
	while (lst->next != NULL)
	{
		lst = lst->next;
		auxlst->next = ft_lstnew(lst->content);
		if (!(auxlst->next))
		{
			ft_lstclear(&firstnode, del);
			return (NULL);
		}
		auxlst = auxlst->next;
		auxlst->content = (*f)(auxlst->content);
		auxlst->next = NULL;
	}
	return (firstnode);
}
