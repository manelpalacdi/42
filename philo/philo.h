/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:17:44 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/20 13:31:35 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				index;
	int				status;
	unsigned int	ate_time;
	int				r_fork;
	int				l_fork;
	pthread_t		*id;
}	t_philo;

typedef struct s_args
{
	int	nphilo;
	int	die_t;
	int	eat_t;
	int	sleep_t;
	int	eat_max;
}	t_args;

#endif
