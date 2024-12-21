/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antofern <antofern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:05:28 by antofern          #+#    #+#             */
/*   Updated: 2024/12/21 15:13:22 by antofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//NO PROBADA
void	infile_to_stdin(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(infile);
		exit(1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(NULL);
		exit(1);
	}
	close(fd);
}

void	stdout_to_outfile(char *outfile)
{
	int	fd;

	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 00664);
	if (fd == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(outfile);
		exit(1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(NULL);
		exit(1);
	}
	close(fd);
}

void	stdout_to_pipe(t_pipe pip)
{
	if (dup2(pip[1], STDOUT_FILENO) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(NULL);
		exit(1);
	}
	close(pip[1]);
}
