/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingkim <mingkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:37:53 by mingkim           #+#    #+#             */
/*   Updated: 2022/04/09 22:11:56 by mingkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gnl에서 controller를 호출한다.
// controller는 현재 content에 줄바꿈이 있는지 검사를한다.
// 만약 줄바꿈이 있다면 t_malloc과 split_newline을 이용해서 next 구조체를 만들고,
// 줄바꿈 뒷 부분을 next->content에 넣어둔다.
// 줄바꿈이 없다면

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
		if (((*file)->eof) && ((*file)->eof) == size)
		{
			size++;
			break ;
		}
		size++;
	}
	content[size] = 0x00;
	(*file)->eof -= size;
	printf("file->eof = %d\n", (*file)->eof);
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
	free(((*file)->content));
	j = 0;
	while (buf[j] && i < size)
		full_sentence[i++] = buf[j++];
	full_sentence[i] = 0x00;
	(*file)->content = full_sentence;
	return (full_sentence);
}

char	*save_remain(t_file**file, t_file **nxt, char *line)
{
	ssize_t	idx;
	ssize_t	j;
	ssize_t	len;
	char	*remain;

	idx = 0;
	j = 0;
	len = (*file)->len;
	while (line[idx] && line[idx++] != '\n')
		;
	remain = (char *)malloc(sizeof(char) * (len - idx + 1));
	if (!remain)
		return (free_fdfile(file));
	while (line[idx] && idx < len)
		remain[j++] = line[idx++];
	remain[j] = 0x00;
	free(((*nxt)->content));
	(*nxt)->content = remain;
	return (remain);
}

char	*controller(t_file **file, int fd)
{
	char	*res;
	char	*line;
	char	*remain;
	t_file	*nxt;

	line = (*file)->content;
	while (find_newline(file) == -1 && !((*file)->eof))
		line = read_buffer(file);
	if (!line)
		return (free_fdfile(file));
	res = split_newline(file);
	if (!res)
		return (free_fdfile(file));
	if ((*file)->content)
		free(((*file)->content));
	(*file)->content = res;
	nxt = t_malloc(fd);
	if (!nxt)
		return (free_fdfile(file));
	(*file)->next = nxt;
	remain = save_remain(file, &nxt, line);
	if (!remain)
		return (free_fdfile(file));
	nxt->content = remain;
	return (((*file)->content));
}

char	*get_next_line(int fd)
{
	static t_file	*flist[OPEN_MAX];
	t_file			*file;
	char			*result;

	if (fd < 0 || BUFFER_SIZE < 0 || fd >= OPEN_MAX)
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
	if (file->next)
		flist[fd] = file->next;
	if (file->content)
		free(file->content);
	if (file)
		free(file);
	return (result);
}
