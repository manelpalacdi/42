/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:37:26 by mpalacin          #+#    #+#             */
/*   Updated: 2024/01/26 10:37:58 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
