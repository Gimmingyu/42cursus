/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:06:51 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/22 16:47:48 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char *cmd, char **env)
{
	size_t	idx;
	char	**line;

	line = ft_split(cmd, ' ');
	// access, execve, parsing, 
}
