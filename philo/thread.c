/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:00:19 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/22 13:01:08 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_pargs *pargs)
{
	struct timeval	tv;
	unsigned long	time;

	gettimeofday(&tv, NULL);
	time = 1000000 * tv.tv_sec + tv.tv_usec;
	if (time > 2147483647)
	{
		write(2, "timeout error\n", 14);
		return (-1);
	}
	if (time - pargs->p.ate_time > pargs->args.die_t)
	{
		ft_putnbr_fd((int)time, 1);
		write(1, " ", 1);
		ft_putnbr_fd(pargs->p.index + 1, 1);
		write(1, " died\n", 6);
		return (-1);
	}
	return (0);
}

void	update(t_args *args)
{
	t_pargs	*pargs;
	
	&pargs->args = args;
	while (i < args->nphilo)
	{
		&pargs->p = &args->p[i];
		if (check_death(pargs))
			break();
		i++;
		if (i == args->nphilo)
			i = 0;
	}
	args->end = 1;
}

void	thread_start(t_pargs *pargs)
{
	while (pargs->p->ate_count < pargs->args->eat_max ||
			!(pargs->args->end))
	{
		if (pargs->args->nphilo == 1)
			usleep(pargs->args->die_t);
		else
		{
			if (eat(pargs) < 0)
				return ;
			if (sleep(pargs) < 0)
				return ;
			if (think(pargs) < 0)
				return ;
		}
	}
}
