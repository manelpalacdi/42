/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:17:44 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/28 11:57:58 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	int				index;
	unsigned long	ate_time;
	int				ate_count;
	pthread_t		*id;
}	t_philo;

typedef struct s_args
{
	int				nphilo;
	t_philo			*p;
	pthread_mutex_t	*forks;
	unsigned long	die_t;
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

int		init_args(int argc, char **argv, t_args *args);
int		init_philo(t_philo *p, char *nphilo);
int		init_thread(t_args *args);
void	*thread_start(void *ref);
void	*update(void *ref);
int		print_status(int i, char *s);
int		eat(t_pargs *pargs);
int		psleep(t_pargs *pargs);
int		think(t_pargs *pargs);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
#endif
