/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:16:23 by mingkim           #+#    #+#             */
/*   Updated: 2022/03/30 21:33:50 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_size_or_newline(char *buf, int usage)
{
	int	i;

	if (usage == -1)
	{
		i = 0;
		while (*(buf + i))
			i++;
		return (i);
	}
	else
	{
		i = 0;
		while (*(buf + i))
		{
			if (*(buf + i) == '\n')
				return (i);
			i++;
		}
		return (-1);
	}
}

char	*concat(char *content, char *buf)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = get_size_or_newline(content, -1);
	j = get_size_or_newline(buf, -1);
	ptr = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (content[i])
	{
		ptr[i] = content[i];
		i++;
	}
	j = 0;
	while (buf[j])
		ptr[i++] = buf[j++];
	ptr[i] = 0x00;
	return (ptr);
}

char	*read_join(int fd, t_file *file)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	int		len;

	len = read(fd, buf, BUFFER_SIZE);
	while (len && get_size_or_newline(buf, 1) == -1 && *buf)
	{
		temp = concat(file->content, buf);
		if (!temp)
			return (NULL);
		file->content = temp;
		len = read(fd, buf, BUFFER_SIZE);
	}
	temp = concat(file->content, buf);
	if (file->content)
		free(file->content);
	if (!temp || !*temp)
		return (NULL);
	file->content = temp;
	return (split_ret(file, temp));
}

char	*split_ret(t_file *file, char *buf)
{
	size_t	idx;
	size_t	j;
	size_t	buf_size;
	char	*ret;
	char	*next_content;

	j = 0;
	idx = get_size_or_newline(buf, 1);
	buf_size = get_size_or_newline(buf, -1);
	ret = (char *)malloc(sizeof(char) * (idx + 1));
	next_content = (char *)malloc(sizeof(char) * (buf_size - idx + 1));
	if (!ret || !next_content)
		return (NULL);
	while (j <= idx && *buf)
		ret[j++] = *buf++;
	ret[j] = 0x00;
	buf_size -= j;
	j = 0;
	while (j < buf_size && *buf)
		next_content[j++] = *buf++;
	next_content[j] = 0x00;
	if (file->content)
		free(file->content);
	file->content = next_content;
	return (ret);
}
