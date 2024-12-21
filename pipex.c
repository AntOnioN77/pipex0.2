/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antofern <antofern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:07:27 by antofern          #+#    #+#             */
/*   Updated: 2024/12/21 16:16:20 by antofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	args_error(void)
{
	write(1, "Incorrect number of arguments.\n"
		"Use ./pipex <infile> <command 1> <command 2> outfile", 84);
	exit(1);
}

int	first_child(char **argv, char **env, t_pipe pip)
{
	pid_t	pid;

	if (pipe(pip) == -1)
	{
		perror(NULL);
		exit(1);
	}
	pid = fork();
	if (pid == 0)
	{
		infile_to_stdin(argv[1]);
		stdout_to_pipe(pip);
		close(pip[0]);
		exec_cmd(2, argv, env);
	}
	close(pip[1]);
	return (pid);
}

int	last_child(char **argv, char **env, t_pipe pip)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (dup2(pip[0], STDIN_FILENO) == -1)
		{
			perror(NULL);
			exit(1);
		}
		close(pip[0]);
		stdout_to_outfile(argv[4]);
		exec_cmd(3, argv, env);
	}
	close(pip[0]);
	return (pid);
}

int	main(int argc, char **argv, char **env)
{
	t_pipe	pip;
	int		status;
	int		pid_last;

	if (argc != 5)
		args_error();
	if (ft_strlen(argv[1]) >= (PATH_MAX + NAME_MAX)
		|| ft_strlen(argv[2]) >= (PATH_MAX + NAME_MAX)
		|| ft_strlen(argv[3]) >= (PATH_MAX + NAME_MAX)
		|| ft_strlen(argv[4]) >= (PATH_MAX + NAME_MAX))
	{
		ft_putstr_fd(strerror(ENAMETOOLONG), 2);
		return (ENAMETOOLONG);
	}
	first_child(argv, env, pip);
	pid_last = last_child(argv, env, pip);
	waitpid(pid_last, &status, 0);
	wait(NULL);
	return ((((status) & 0xff00) >> 8));
}
