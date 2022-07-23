/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimmingyu <kimmingyu@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:59:35 by mingkim           #+#    #+#             */
/*   Updated: 2022/07/23 12:00:40 by kimmingyu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
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

#endif