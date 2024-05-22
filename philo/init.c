/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:55:11 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/22 12:44:16 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc != 5 && argc != 6)
	{
		write(2, "Wrong number of arguments\n", 26);
		return (-1);
	}
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write(2, "Wrong format\n", 13);
				return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	init_args(int argc, char **argv, t_args *args)
{
	if (check_args(argc, argv) < 0)
		return (-1);
	args->nphilo = ft_atoi(argv[1]);
	args->forks = malloc(nphilo + 1);
	if (!(args->forks))
	{
		write(2, "Failed memory initialization\n", 29);
		return (-1);
	}
	memset(args->forks, '0', nphilo);
	args->forks[nphilo] = '\0';
	args->die_t = ft_atoi(argv[2]);
	args->eat_t = ft_atoi(argv[3]);
	args->sleep_t = ft_atoi(argv[4]);
	if (argc == 6)
		args->eat_max = ft_atoi(argv[5]);
	args->end = 0;
	return (0);
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
		p[i]->r_fork = '0';
		p[i]->l_fork = '0';
	}
	return (0);
}

int	init_thread(t_args *args)
{
	int		i;
	t_pargs	*pargs;

	&pargs->args = args;
	i = 0;
	while (i < nphilo)
	{
		&pargs->p = &args->p[i];
		if (pthread_create(&(args->p[i]->id), NULL, thread_start, pargs) < 0)
		{
			write(2, "Failed to create thread\n", 24);
			return (-1);
		}
		if (pthread_detach(args->p[i]->id) < 0)
		{
			write(2, "Failed to detach thread\n", 24);
			return (-1);
		}
	}
	if (pthread_create(&(args->update_id), NULL, update, args) < 0)
	{
		write(2, "Failed to create thread\n", 24);
		return (-1);
	}
	if (pthread_detach(args->update_id) < 0)
	{
		write(2, "Failed to detach thread\n", 24);
		return (-1);
	}
}
