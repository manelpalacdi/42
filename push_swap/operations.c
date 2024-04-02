/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:08:49 by mpalacin          #+#    #+#             */
/*   Updated: 2024/03/14 13:46:55 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_swap(t_stk **stk)
{
	int	aux;
	if (!stk)
		return ;
	if (ft_lstsize(*stk) < 2)
		return ;
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
