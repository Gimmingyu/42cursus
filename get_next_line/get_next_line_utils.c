/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:47:52 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/10 19:11:53 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*allocate_file(int fd)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->next = NULL;
	file->fd = fd;
	file->len = 0;
	file->nl_idx = 0;
	return (file);
}

ssize_t	get_next_file(t_file *file, int fd)
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
		file->next = nxt;
	// printf("file->content = %s\n", file->content);
	// printf("nxt->content = %s\n", nxt->content);
	return (size);
}

t_file	*get_exist_fdfile(t_file **flist, int fd)
{
	t_file	*file;
	t_file	*temp;

	file = flist[fd];
	temp = NULL;
	while (file)
	{
		if (file->fd == fd)
			return (file);
		temp = file;
		file = file->next;
	}
	file = allocate_file(fd);
	if (!file)
		return (NULL);
	if (!temp)
		flist[fd] = file;
	else
		temp->next = file;
	return (file);
}

ssize_t read_buffer(int fd, t_file *file)
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
	t_file		*f_temp;

	f_temp = flist[fd];
	if (file != f_temp)
	{
		while (f_temp->next != file)
			f_temp = f_temp->next;
		f_temp->next = file->next;
	}
	else
		flist[fd] = file->next;
	free(file);
	file = NULL;
	return (NULL);
}