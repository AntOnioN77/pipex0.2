/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antofern <antofern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:32:42 by antofern          #+#    #+#             */
/*   Updated: 2024/12/21 12:39:41 by antofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <linux/limits.h>
# include "libft/headers/libft.h"

//Taken from the header: linux/limits.h
# define NAME_MAX 255
# define PATH_MAX 4096

typedef int	t_pipe[2];

//EXEC_CMD.C
void	exec_cmd(int index_arg, char **argv, char **env);
char	**ft_splitqu(char const *s, char c);

//REDIRECTIONS.C
void	infile_to_stdin(char *infile);
void	stdout_to_outfile(char *outfile);
void	stdout_to_pipe(t_pipe pip);

#endif