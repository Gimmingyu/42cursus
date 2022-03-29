/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:39:18 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/29 21:55:54 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

typedef struct s_file
{
	int				fd;
	char			*content;
	struct s_file	*next;
}	t_file;

char	*get_next_line(int fd);
char	*read_join(int fd, t_file **flist, t_file *file);
size_t	get_size(char *buf);
int		find_newline(char *buf);
#endif
