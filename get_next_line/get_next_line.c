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

ssize_t	get_newline_idx(t_file **flist, t_file *file, int fd)
{
	ssize_t	bufsize;
	ssize_t	nl_idx;
	ssize_t idx;
	char	*content;
	t_file	*temp;

	content = file->content;
	nl_idx = 0;
	idx = file->nl_idx;
	temp = file;
	while (idx <= file->len)
	{
		if (idx == file->len)
		{
			idx = 0;
			bufsize = get_next_file(temp, fd);
			if (!bufsize)
				break ;
			else if (bufsize == -1)
				return ((ssize_t)free_fdfile(flist, file, fd));
			temp = temp->next;
			content = temp->content;
			continue ;
		}
		if (content[idx++] == NEWLINE)
			break ;
		nl_idx++;
	}
	return (nl_idx);
}

char	*get_result_line(t_file **flist, t_file *file, ssize_t nl_idx, int fd)
{
	char	*result;
	char	*now;
	ssize_t	i;
	ssize_t	j;

	result = (char *)malloc(sizeof(char) * (nl_idx + 1));
	if (!result)
		return (free_fdfile(flist, file, fd));
	result[nl_idx] = 0x00;
	i = 0;
	now = file->content;
	j = file->nl_idx;
	while (now && j <= file->len)
	{
		if (i == nl_idx)
			break ;
		if (j == file->len)
		{
			free(file);
			file = file->next;
			now = file->content;
			// printf("now is now %s\n", now);
			j = 0;
		}
		else
			result[i++] = now[j++];
		// printf("i = %zd, j = %zd\n", i, j);
		// printf("result = %s\n", result);
	}
	file->nl_idx = j;
	return (result);
}

char	*get_next_line(int fd)
{
	static t_file	*flist[OPEN_MAX];
	t_file			*file;
	ssize_t			len;
	ssize_t			nl_idx;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	file = get_exist_fdfile(flist, fd);
	if (!file)
		return (NULL);
	if (!(file->len))
	{
		len = read_buffer(fd, file);
		if (len <= 0)
			return (free_fdfile(flist, file, fd));
	}
	nl_idx = get_newline_idx(flist, file, fd);
	if (nl_idx)
		return (get_result_line(flist, file, nl_idx, fd));
	return (free_fdfile(flist, file, fd));
}