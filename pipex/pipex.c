/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:58:37 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/22 16:23:29 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(int *fd, char **av, char **env)
{
	int	outfile;

	outfile = open(av[4], O_RDWR, 0777);
	if (outfile == -1)
		response_error("Error\n", 1);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		response_error("Error\n", 1);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		response_error("Error\n", 1);
	close(fd[1]);
	pipex(av[3], env);
}

void	child_process(int *fd, char **av, char **env)
{
	int	infile;

	infile = open(av[1], O_RDONLY, 0777);
	if (infile == -1)
		response_error("Error\n", 1);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		response_error("Error\n", 1);
	if (dup2(infile, STDIN_FILENO) == -1)
		response_error("Error\n", 1);
	close(fd[0]);
	pipex(av[2], env);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;
	int		stat_loc;

	if (ac != 5)
		response_error("Error\n", 1);
	if (pipe(fd) == -1)
		response_error("Error\n", 1);
	pid = fork();
	if (pid == 0)
		child_process(fd, av, env);
	else if (pid == -1)
		response_error("Error\n", 1);
	waitpid(pid, &stat_loc, WNOHANG);
	parent_process(fd, av, env);
	return (0);
}
