/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:17:44 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/22 13:01:10 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				index;
	int				status;
	unsigned long	ate_time;
	int				ate_count;
	pthread_t		*id;
}	t_philo;

typedef struct s_args
{
	int				nphilo;
	t_philo			*p;
	pthread_mutex_t	*forks;
	int				die_t;
	int				eat_t;
	int				sleep_t;
	int				eat_max;
	pthread_t		*update_id;
	int				end;
}	t_args;

typedef struct s_pargs
{
	t_philo	*p;
	t_args	*args;
}	t_pargs;

#endif
