/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimmingyu <kimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:58:37 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/21 22:10:11 by kimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	child;

	if (ac != 5 || pipe(fd) == -1)
		response_error("Error\n", 1);
	child = fork();
	if (child == 0)
		printf("child process");
	else
		response_error("Error\n", 1);
	waitpid(child, NULL, WNOHANG);
	return (0);
}
