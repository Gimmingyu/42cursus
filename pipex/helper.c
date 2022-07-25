/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:06:51 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/25 13:51:55 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	response_error(char *msg, int signal)
{
	write(2, msg, ft_strlen(msg));
	exit(signal);
}

char	*find_path(char *cmd, char **env)
{
	size_t	i;
	size_t	j;
	char	**env_path;
	char	*temp;

	i = 0;
	j = 0;
	while (ft_strncmp(env[i], "PATH", 4))
		i++;
	env_path = ft_split(env[i] + 5, ':');
	while (env_path[j])
	{
		temp = ft_strjoin(env_path[j], cmd);
		if (!access(temp, X_OK))
			break ;
		free(temp);
		temp = NULL;
		j++;
	}
	ft_malloc_error(env_path);
	return (temp);
}

void	execve_runner(char *cmd, char **full_command, char **env)
{
	if (execve(cmd, full_command, env) == -1)
		response_error("Error\n", 1);
}

void	solution(char *cmd, char **env)
{
	size_t	idx;
	char	**line;
	char	*command;
	char	*path;

	line = ft_split(cmd, ' ');
	if (!access(line[0], X_OK))
		execve_runner(line[0], line, env);
	command = ft_strjoin("/", line[0]);
	path = find_path(command, env);
	free(command);
	if (!path)
	{
		ft_malloc_error(line);
		response_error("Error\n", 1);
	}
	execve_runner(path, line, env);
	ft_malloc_error(line);
	free(path);
}
