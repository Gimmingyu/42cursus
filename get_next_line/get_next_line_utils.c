/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:47:52 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/09 18:55:21 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	find_newline(t_file **file)
{
	char	*line;
	ssize_t	idx;

	idx = 0;
	line = (*file)->content;
	while (line[idx])
	{
		if (line[idx] == '\n')
		{
			(*file)->newline = idx;
			return (idx);
		}
		idx++;
	}
	(*file)->len = idx;
	return (-1);
}

t_file	*t_malloc(int fd)
{
	t_file	*new_file;
	char	*new_content;

	new_file = (t_file *)malloc(sizeof(t_file));
	if (!new_file)
		return (NULL);
	new_file->content = (char *)malloc(sizeof(char));
	if (!(new_file->content))
		return (free_fdfile(&new_file));
	new_file->fd = fd;
	new_file->eof = 0;
	new_file->len = 1;
	new_file->newline = 0;
	new_file->next = NULL;
	return (new_file);
}

void	*clear_buffer(const char *buf)
{
	size_t	idx;
	char	*temp;

	temp = buf;
	idx = 0;
	while (idx < BUFFER_SIZE + 1)
		temp[idx++] = 0x00;
}

char	*read_buffer(t_file **file)
{
	char	buf[BUFFER_SIZE + 1];
	char	*line;
	ssize_t	len;

	clear_buffer(buf);
	len = read((*file)->fd, buf, BUFFER_SIZE);
	if (len <= 0)
		return (NULL);
	buf[len] = 0x00;
	if (len < BUFFER_SIZE)
		(*file)->eof = 1;
	(*file)->len += len;
	line = concatenate(buf, file);
	if (!line)
		return (free_fdfile(file));
	return ((*file)->content);
}

void	*free_fdfile(t_file **file)
{
	t_file		*current;
	t_file		*nxt;

	current = *file;
	while (current)
	{
		nxt = current->next;
		free(current);
		if (current->content)
			free(current->content);
		current = nxt;
	}
	*file = NULL;
	return (NULL);
}
