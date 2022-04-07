/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:37:53 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/07 21:03:39 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

t_file	*tmalloc(t_file *file, char *buf)
{
	t_file	*temp;

	temp = (t_file *)malloc(sizeof(t_file));
	if (!temp)
		return (NULL);
	temp->fd = file->fd;
	temp->next = NULL;
	file->content = buf;
	file->next = temp;
	return (temp);
}

char	*parse_fdfile(t_file *file, size_t idx)
{
	size_t	i;
	size_t	len;
	char	*ptr;
	t_file	*nxt;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(file->content) + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, file->content, ft_strlen(file->content) + 1);
	i = 0;
	while (i < idx)
	{
		nxt = file->next;
		len = ft_strlen(nxt->content) + ft_strlen(ptr) + 1;
		ptr = (char *)malloc(sizeof(char) * (len));
		if (!ptr)
			return (NULL);
		ft_strlcat(ptr, nxt->content, len);
	}
	return (ptr);
}

char	*read_line(t_file *file)
{
	t_file	*temp;
	size_t	len;
	size_t	idx;
	char	buf[BUFFER_SIZE + 1];
	char	*ret;

	len = read(file->fd, buf, BUFFER_SIZE);
	temp = tmalloc(file, buf);
	ret = NULL;
	idx = 0;
	if (!temp)
		return (0);
	while (len && find_newline(buf) == -1)
	{
		idx++;
		len = read(file->fd, buf, BUFFER_SIZE);
		temp->next = tmalloc(temp, buf);
		temp = temp->next;
	}
	if (len != -1 && find_newline(temp->content))
		ret = parse_fdfile(file, idx);
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_file	*flist[OPEN_MAX];
	t_file			*file;
	char			*ret;

	if (flist[fd])
		file = flist[fd];
	else
	{
		file = (t_file *)malloc(sizeof(t_file));
		if (!file)
			return (NULL);
		file->fd = fd;
		file->content = NULL;
		flist[fd] = file;
	}
	ret = read_line(file);
	return (NULL);
}
