/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:08:49 by mpalacin          #+#    #+#             */
/*   Updated: 2024/03/07 12:18:12 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *lst)
{
	int	tmp;

	if (ft_lstsize(lst) < 2)
		return ;
	tmp = lst->content;
	lst->content = lst->next->content;
	a->next->content = tmp;
}

void	ft_push(t_list **lst, t_list *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_rotate(t_list **lst)
{
	int		size;
	int		i;
	t_list	*aux1;
	t_list	*aux2;
	int		holdval;

	size = ft_lstsize(*lst);
	i = 0;
	aux2 = *lst;
	holdval = (*lst)->content;
	while (size > 1)
	{
		while (i < size - 1)
		{
			aux1 = aux2;
			aux2 = aux1->next;
			i++;
		}
		aux1->content = aux2->content;
		size--;
	}
	ft_lstlast(*lst)->content = holdval;
}

void	ft_rrotate(t_list **lst)
{
	int		i;
	int		size;
	int 	holdval;

	i = 0;
	size = ft_lstsize(*lst);
	if (size > 1)
	{
		holdval = ft_lstlast(*lst)->content;
		while (i < size - 1)
		{
			(*lst)->next->content = (*lst)->content;
			*lst = (*lst)->next;
		}
		(**lst)->content = holdval;
	}
}

void	ft_pop(t_list **lst)
{
	t_list *aux;
	int		size;

	size = ft_lstsize(*lst);
	if (ft_lstsize(*lst) > 1)
	{
		aux = *lst;
		(*lst) = (*lst)->next;
		ft_lstdelone(aux, free);
	}
}
