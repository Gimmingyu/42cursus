/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:39:18 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/10 15:36:31 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef NEWLINE
#  define NEWLINE 10
# endif

typedef struct s_file
{
	int				fd;
	ssize_t			len;
	ssize_t			nl_idx;
	char			content[BUFFER_SIZE + 1];
	struct s_file	*next;
}	t_file;

char	*get_next_line(int fd);
char	*free_fdfile(t_file **flist, t_file *file, int fd);
char	*get_result_line(t_file **flist, t_file *file, ssize_t nl_idx, int fd);

ssize_t read_buffer(int fd, t_file *file);
ssize_t	get_until_newline(t_file **flist, t_file *file, int fd);
ssize_t	get_next_file(t_file *file, int fd);
ssize_t	fnew(char *temp);

ssize_t	get_next_content(char **now, t_file *file);

t_file	*get_exist_fdfile(t_file **flist, int fd);
t_file	*allocate_file(int fd);
#endif
