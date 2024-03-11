/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:48:12 by mpalacin          #+#    #+#             */
/*   Updated: 2024/02/05 12:42:22 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	printchar(char c, long long int *printcount);
void	printdecimalnbr(long long int n, long long int *printcount);
void	printbasenbr(unsigned long long int n, unsigned int base, char *digits,
			long long int *printcount);
int		ft_printf(char const *str, ...);

#endif
