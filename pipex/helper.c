/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimmingyu <kimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:06:51 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/23 12:22:51 by kimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execve_command(char *infile, char **line, char **env)
{
	printf("infile = %s\n", infile);
	size_t	i;
	i = 0;
	while (line[i])
	{
		printf("line[%zu] = %s\n", i, line[i]);
		i++;
	}
	if (execve(infile, line, env) == -1)
		response_error("Error\n", 1);
}

char	*parse_path(char *cmd, char **env)
{
	size_t	i;
	size_t	j;
	char	**env_path;
	char	*temp;

	i = 0;
	while (ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	env_path = ft_split(env[i] + 5, ':');
	j = 0;
	while (env_path[j])
	{
		temp = ft_strjoin(env_path[j], cmd);
		if (access(temp, X_OK) == 0)
		{
			ft_malloc_error(env_path);
			return (temp);
		}
		free(temp);
		j++;
	}
	ft_malloc_error(env_path);
	return (NULL);
}

void	solution(char *cmd, char **env)
{
	size_t	idx;
	char	**line;
	char	*command;
	char	*path;

	line = ft_split(cmd, ' ');
	// access == 0 이면 성공
	if (!access(line[0], X_OK))
		execve_command(line[0], line, env);
	command = ft_strjoin("/", line[0]);
	path = parse_path(command, env);
	free(command);
	if (!path)
	{
		ft_malloc_error(line);
		response_error("Error\n", 1);
	}
	execve_command(path, line, env);
	ft_malloc_error(line);
	free(path);
}
