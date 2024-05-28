/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:44:20 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/28 11:04:55 by mpalacin         ###   ########.fr       */
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
	if (lock_mutex(&(pargs->args->forks[pargs->p->index])) < 0)
		return (-1);
	if (print_status(pargs->p->index, "has taken a fork\n") < 0)
		return (-1);
	if (lock_mutex(&(pargs->args->forks[(pargs->p->index + 1)
					% pargs->args->nphilo])) < 0)
		return (-1);
	if (print_status(pargs->p->index, "has taken a fork\n") < 0)
		return (-1);
	if (print_status(pargs->p->index, "is eating\n") < 0)
		return (-1);
	if (pargs->args->eat_max > 0)
		pargs->p->ate_count += 1;
	if (usleep(pargs->args->eat_t) < 0)
		return (-1);
	if (unlock_mutex(&(pargs->args->forks[pargs->p->index])) < 0)
		return (-1);
	if (unlock_mutex(&(pargs->args->forks[(pargs->p->index + 1)
					% pargs->args->nphilo])) < 0)
		return (-1);
	if (pthread_mutex_destroy(&(pargs->args->forks[pargs->p->index])) < 0)
		return (-1);
	if (pthread_mutex_destroy(&(pargs->args->forks[pargs->p->index + 1])) < 0)
		return (-1);
	return (0);
}

int	psleep(t_pargs *pargs)
{
	if (print_status(pargs->p->index, "is sleeping\n") < 0)
		return (-1);
	if (usleep(pargs->args->sleep_t) < 0)
	{
		write(2, "Failed to usleep\n", 17);
		return (-1);
	}
	return (0);
}

int	think(t_pargs *pargs)
{
	if (print_status(pargs->p->index, "is thinking\n") < 0)
		return (-1);
	return (0);
}
