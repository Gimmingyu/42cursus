/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:37:53 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/11 20:31:17 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	get_next_size(ssize_t *size, t_file *file, int fd, t_file **flist)
{
	t_file	*temp;
	ssize_t	idx;
	ssize_t	next_len;
	char	*content;

	temp = file;
	content = file->content;
	idx = file->start;
	while (idx <= temp->len)
	{
		if (idx == temp->len)
		{
			next_len = get_next_file(&temp, fd);
			if (next_len == -1)
				return ((ssize_t)free_fdfile(flist, file, fd));
			if (!next_len)
				break ;
			content = temp->content;
			idx = 0;
		}
		(*size)++;
		if (content[idx++] == NEWLINE)
			break ;
	}
	return (*size);
}

ssize_t	get_result_size(t_file **flist, t_file *file, int fd)
{
	ssize_t	size;

	size = 0;
	size = get_next_size(&size, file, fd, flist);
	if (!size)
		return (0);
	return (size);
}

void	make_result_line(t_file **flist, char **result, ssize_t size, \
t_file *file)
{
	t_file	*temp;
	char	*content;
	ssize_t	idx;
	ssize_t	i;

	i = 0;
	temp = file;
	content = temp->content;
	idx = temp->start;
	while (idx <= (temp->len) && content)
	{
		if (i == size)
			break ;
		if (idx == (temp->len))
			idx = get_next_content(&temp, &content);
		else
			(*result)[i++] = content[idx++];
	}
	temp->start = idx;
	flist[temp->fd] = temp;
}

char	*get_result_line(t_file **flist, t_file *file, ssize_t size, int fd)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (free_fdfile(flist, file, fd));
	result[size] = 0x00;
	make_result_line(flist, &result, size, file);
	return (result);
}

char	*get_next_line(int fd)
{
	static t_file	*flist[OPEN_MAX];
	t_file			*file;
	ssize_t			len;
	ssize_t			size;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!flist[fd])
		file = allocate_file(fd);
	else
		file = flist[fd];
	if (!file)
		return (NULL);
	if (!(file->len))
	{
		len = read_buffer(fd, file);
		if (len <= 0)
			return (free_fdfile(flist, file, fd));
	}
	size = get_result_size(flist, file, fd);
	if (size)
		return (get_result_line(flist, file, size, fd));
	return (free_fdfile(flist, file, fd));
}
