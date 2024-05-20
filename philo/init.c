/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:55:11 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/20 12:17:33 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_thread(t_philo *p, char **argv)
{
	int	i;

	i = 0;
	while (i < nphilo)
	{
		if (pthread_create(&(p[i]->id), NULL, thread_start, argv) < 0)
		{
			write(2, "Failed to create thread\n", 24);
			return (-1);
		}
		if (pthread_detach(p[i]->id) < 0)
		{
			write(2, "Failed to detach thread\n", 24);
			return (-1);
		}
	}
}

int	init_philo(t_philo *p, char *nphilo)
{
	int	i;
	int	nphilo;

	i = 0;
	nphilo = ft_atoi(nphilo);
	p = malloc(nphilo * sizeof(t_philo));
	if (!p)
	{
		write(2, "Failed memory initialization\n", 29);
		return (-1);
	}
	while (i < nphilo)
	{
		p[i]->index = i;
		p[i]->status = 0;
		p[i]->ate_time = 0;
		p[i]->r_fork = 0;
		p[i]->l_fork = 0;
	}
	return (0);
}
