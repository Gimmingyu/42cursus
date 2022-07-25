/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:59:35 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/25 13:52:46 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef enum e_flag
{
	TRUE = 1,
	FALSE = 0,
	ERR = -1,
}	t_flag;

void	response_error(char *msg, int flag);
void	solution(char *cmd, char **env);

char	*find_path(char *cmd, char **env);
void	execve_runner(char *cmd, char **full_command, char **env);
#endif