/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:47:52 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/12 20:42:39 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_file	*allocate_file(int fd)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->next = NULL;
	file->fd = fd;
	file->len = 0;
	file->start = 0;
	return (file);
}

ssize_t	get_next_file(t_file **temp, int fd)
{
	t_file	*nxt;
	ssize_t	size;

	nxt = allocate_file(fd);
	if (!nxt)
		return (-1);
	size = read_buffer(fd, nxt);
	if (size <= 0)
		free(nxt);
	else
		(*temp)->next = nxt;
	(*temp) = (*temp)->next;
	return (size);
}

ssize_t	read_buffer(int fd, t_file *file)
{
	ssize_t	len;

	len = read(fd, file->content, BUFFER_SIZE);
	if (len <= 0)
		return (len);
	file->len = len;
	(file->content)[len] = 0x00;
	return (len);
}

char	*free_fdfile(t_file **flist, t_file *file, int fd)
{
	t_file	*f_temp;
	t_file	*nxt;

	f_temp = file;
	while (f_temp)
	{
		nxt = f_temp->next;
		free(f_temp);
		f_temp = nxt;
	}
	f_temp = NULL;
	flist[fd] = NULL;
	return (NULL);
}

ssize_t	get_next_content(t_file **temp, char **content)
{
	free(*temp);
	(*temp) = (*temp)->next;
	(*content) = (*temp)->content;
	return ((*temp)->start);
}
