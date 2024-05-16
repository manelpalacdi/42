/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalacin <mpalacin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:56:13 by mpalacin          #+#    #+#             */
/*   Updated: 2024/05/16 11:23:49 by mpalacin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# define SHNAME "script.sh"

void	check_input_file(const char *in);
void	check_output_file(const char *out);
int		fork_execute(int in, int out, const char *cmd, char **env);
char	*get_path(char *cmd, char **env);
int		check_args(char **argv, int argc, int *i, int *in);
int		here_doc(char **argv);
void	exit_error(const char *error);
void	free_matrix(char **m);

#endif
