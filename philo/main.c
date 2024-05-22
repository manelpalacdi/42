/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:52:07 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/22 11:00:49 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	*args;

	if (init_args(argc, argv, args) < 0)
		return (1);
	if (init_philo(args->p, args->nphilo) < 0)
		return (1);
	if (init_thread(args) < 0)
		return (1);
}
