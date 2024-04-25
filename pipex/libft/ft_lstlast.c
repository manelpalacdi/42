/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:21:58 by mpalacin          #+#    #+#             */
/*   Updated: 2024/01/26 10:15:35 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*auxlst;

	auxlst = lst;
	if (!auxlst)
		return (auxlst);
	while (auxlst->next != NULL)
		auxlst = auxlst->next;
	return (auxlst);
}
