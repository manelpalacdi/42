/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:44:20 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/22 13:01:06 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	lock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) < 0)
	{
		write(2, "Failed to lock mutex\n", 21);
		return (-1);
	}
	return (0);
}

static int	unlock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) < 0)
	{
		write(2, "Failed to unlock mutex\n", 23);
		return (-1);
	}
	return (0);
}

int	eat(t_pargs *pargs)
{
	if (lock_mutex(pargs->args->forks[pargs->p->index]) < 0)
		return (-1);
	print_status(pargs->p->index, "has taken a fork\n");
	if (lock_mutex(pargs->args->forks[(pargs->p->index + 1)
			% pargs->args->nphilo]) < 0)
		return (-1);
	print_status(pargs->p->index, "has taken a fork\n");
	print_status(pargs->p->index, "is eating\n");
	usleep(pargs->args->eat_t);
	if (unlock_mutex(pargs->args->forks[pargs->p->index]) < 0)
		return (-1);
	if (unlock_mutex(pargs->args->forks[(pargs->p->index + 1)
			% pargs->args->nphilo]) < 0)
		return (-1);
	return (0);
}

int	sleep(t_pargs *pargs)
{
	print_status(pargs->p->index, "is sleeping\n");
	if (usleep(pargs->args->sleep_t) < 0)
	{
		write(2, "Failed to usleep\n", 17);
		return (-1);
	}
	return (0);
}

int	think(t_pargs *pargs)
{
	print_status(pargs->p->index, "is thinking\n");
	return (0);
}
