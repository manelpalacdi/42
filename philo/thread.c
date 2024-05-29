/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:00:19 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/29 10:52:49 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_status(int i, char *s)
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
	ft_putnbr_fd((int)time, 1);
	write(1, " ", 1);
	ft_putnbr_fd(i, 1);
	write(1, " ", 1);
	ft_putstr_fd(s, 1);
	return (0);
}

static int	check_death(t_pargs *pargs)
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
	if (time - pargs->p->ate_time > pargs->args->die_t)
	{
		ft_putnbr_fd((int)time, 1);
		write(1, " ", 1);
		ft_putnbr_fd(pargs->p->index + 1, 1);
		write(1, " died\n", 6);
		return (-1);
	}
	return (0);
}

void	*update(void *ref)
{
	t_pargs	*pargs;
	int		i;

	i = 0;
	pargs = ref;
	while (i < pargs->args->nphilo)
	{
		pargs->p = &(pargs->args->p[i]);
		if (check_death(pargs))
			break ;
		if (pargs->p->ate_count >= pargs->args->eat_max)
			pargs->args->end = 1;
		i++;
		if (i == pargs->args->nphilo)
			i = 0;
	}
	pargs->args->end = 1;
	write(1, "a", 1);
	return (NULL);
}

void	*thread_start(void *ref)
{
	t_pargs	*pargs;

	pargs = ref;
	if (pargs->args->nphilo == 1)
	{
		if (usleep(pargs->args->die_t) < 0)
			return (NULL);
	}
	while (!(pargs->args->end))
	{
		if (eat(pargs) < 0)
			return (NULL);
		if (pargs->args->end)
			break ;
		if (psleep(pargs) < 0)
			return (NULL);
		if (pargs->args->end)
			break ;
		if (think(pargs) < 0)
			return (NULL);
	}
	return (NULL);
}
