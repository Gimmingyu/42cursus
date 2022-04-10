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

ssize_t	find_newline(t_file **file)
{
	char	*line;
	ssize_t	idx;

	idx = 0;
	if (!((*file)->content))
	{
		(*file)->len = 0;
		return (-1);
	}
	line = (*file)->content;
	while (line[idx])
	{
		if (line[idx] == NEWLINE)
		{
			(*file)->newline = idx;
			return (idx);
		}
		idx++;
	}
	(*file)->len = idx;
	if ((*file)->eof && (*file)->eof == idx)
		return (idx);
	return (-1);
}

t_file	*t_malloc(int fd)
{
	t_file	*new_file;

	new_file = (t_file *)malloc(sizeof(t_file));
	if (!new_file)
		return (NULL);
	new_file->content = (char *)malloc(sizeof(char));
	if (!(new_file->content))
	{
		free_fdfile(&new_file);
		return (NULL);
	}
	new_file->content[0] = 0x00;
	new_file->fd = fd;
	new_file->eof = 0;
	new_file->len = 0;
	new_file->newline = 0;
	new_file->next = NULL;
	return (new_file);
}

void	clear_buffer(char *buf)
{
	size_t			idx;
	unsigned char	*temp;

	temp = (unsigned char *)buf;
	idx = 0;
	while (idx < BUFFER_SIZE + 1)
		temp[idx++] = 0x00;
}

char	*read_buffer(t_file **file, ssize_t *len)
{
	char	buf[BUFFER_SIZE + 1];

	if (*buf)
		clear_buffer(buf);
	*len = read((*file)->fd, buf, BUFFER_SIZE);
	if (*len >= 0)
	{
		buf[*len] = 0x00;
		if (*len < BUFFER_SIZE)
			(*file)->eof = (*file)->len + *len;
		(*file)->len += *len;
		(*file)->content = concatenate(buf, file);
		if (!((*file)->content))
			return (free_fdfile(file));
		return ((*file)->content);
	}
	if ((*file)->content)
		free((*file)->content);
	if (*len == -1)
	{
		(*file)->eof = -1;
		return (NULL);
	}
	return (NULL);
}

char	*free_fdfile(t_file **file)
{
	t_file		*current;
	t_file		*nxt;

	if (!(*file))
		return (NULL);
	current = *file;
	while (current)
	{
		nxt = current->next;
		if (current->content)
		{
			free(current->content);
			current->content = NULL;
		}
		free(current);
		current = NULL;
		current = nxt;
	}
	current = NULL;
	*file = NULL;
	return (NULL);
}
