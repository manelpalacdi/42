/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:06:48 by mpalacin          #+#    #+#             */
/*   Updated: 2024/01/25 10:24:33 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
