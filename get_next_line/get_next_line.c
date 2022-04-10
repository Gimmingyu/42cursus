/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:37:53 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/10 19:12:28 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*split_newline(t_file **file)
{
	char	*content;
	ssize_t	size;

	if (!file)
		return (NULL);
	size = 0;
	(*file)->newline = find_newline(file);
	content = (char *)malloc(sizeof(char) * (((*file)->newline) + 1));
	if (!content)
		return (free_fdfile(file));
	while (size <= ((*file)->newline) && ((*file)->content)[size])
	{
		content[size] = ((*file)->content)[size];
		size++;
	}
	content[size] = 0x00;
	if ((*file)->eof)
		(*file)->eof -= size;
	return (content);
}

char	*concatenate(const char *buf, t_file **file)
{
	char	*full_sentence;
	ssize_t	size;
	ssize_t	i;
	ssize_t	j;

	size = (*file)->len;
	full_sentence = (char *)malloc(sizeof(char) * (size + 1));
	if (!full_sentence)
		return (NULL);
	i = 0;
	while (((*file)->content)[i] && i < size)
	{
		full_sentence[i] = ((*file)->content)[i];
		i++;
	}
	if ((*file)->content)
		free(((*file)->content));
	j = 0;
	while (buf[j] && i < size)
		full_sentence[i++] = buf[j++];
	full_sentence[i] = 0x00;
	(*file)->len = i;
	return (full_sentence);
}

char	*save_remain(t_file**file, t_file **nxt)
{
	ssize_t	idx;
	ssize_t	j;
	ssize_t	len;

	idx = 0;
	j = 0;
	len = (*file)->newline;
	while (idx < len)
		idx++;
	if ((*nxt)->content)
		free(((*nxt)->content));
	(*nxt)->content = (char *)malloc(sizeof(char) * (len - idx + 1));
	if (!(*nxt)->content)
		return (free_fdfile(file));
	while (((*file)->content)[idx] && idx < len)
		((*nxt)->content)[j++] = ((*file)->content)[idx++];
	((*nxt)->content)[j] = 0x00;
	(*nxt)->len = j;
	return ((*nxt)->content);
}

char	*controller(t_file **file, int fd)
{
	char	*res;
	char	*remain;
	t_file	*nxt;
	ssize_t	len;

	(*file)->newline = find_newline(file);
	len = 1;
	while ((*file)->content && find_newline(file) == -1 && ((*file)->eof) >= 0 \
	&& len)
		(*file)->content = read_buffer(file, &len);
	if (!((*file)->content) || !(*(*file)->content))
		return (free_fdfile(file));
	res = split_newline(file);
	if (!res)
		return (free_fdfile(file));
	nxt = t_malloc(fd);
	if (!nxt)
		return (free_fdfile(file));
	(*file)->next = nxt;
	remain = save_remain(file, &nxt);
	if (!remain)
		free_fdfile(&nxt);
	return (res);
}

char	*get_next_line(int fd)
{
	static t_file	*flist[OPEN_MAX];
	t_file			*file;
	char			*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!flist[fd])
		file = t_malloc(fd);
	else
		file = flist[fd];
	if (!file)
		return (NULL);
	result = controller(&file, fd);
	if (!result)
		return (free_fdfile(&file));
	flist[fd] = file->next;
	if (!(file->next))
		flist[fd] = NULL;
	if (file)
		free(file);
	return (result);
}
