/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:37:53 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/08 21:30:25 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*t_malloc(int fd)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->fd = fd;
	file->next = NULL;
	file->content = (char *)malloc(sizeof(char));
	if (!(file->content))
	{
		free(file);
		return (NULL);
	}
	return (file);
}

static char	*save_next(int fd, t_file **file)
{
	t_file	*nxt;
	char	*remain;

	remain = (*file)->content;
	nxt = (*file);
	while (find_newline(remain))
	{
		nxt = t_malloc(fd);
		if (!nxt)
			return (NULL);
		nxt = nxt->next;
	}
	return (NULL);
}

static char	*concatenate(const char *buf, t_file **file)
{
	char	*ptr;
	size_t	size;

	buf[len] = 0x00;
	size = ft_strlen((*file)->content) + ft_strlen(buf);
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (*file)->content, size);
	ft_strlcat(ptr, buf, size);
	if ((*file)->content)
		free((*file)->content);
	(*file)->content = ptr;
	return (ptr);
}

static void	parse_fdfile(int fd, t_file **file)
{
	ssize_t	len;
	char	buf[BUFFER_SIZE + 1];

	len = 1;
	while (len > 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (find_newline((*file)->content) >= 0 || len < BUFFER_SIZE)
			break ;
		concatenate(buf, file);
		if (!(*file)->content)
			return (NULL);
	}
	if (len == -1)
		return (NULL);
	concatenate(buf, file);
	if (!(*file)->content)
		return (NULL);
	save_next(fd, file);
}

char	*get_next_line(int fd)
{
	static t_file	*flist[OPEN_MAX];
	t_file			*file;
	t_file			*nxt;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	if (flist[fd])
		file = flist[fd];
	else
		file = t_malloc(fd);
	if (!file)
		return (NULL);
	parse_fdfile(fd, &file);
	if (!(file->content))
		return (free_fdfile(&file));
	nxt = file->next;
	free(file);
	flist[fd] = nxt;
	return (file->content);
}
