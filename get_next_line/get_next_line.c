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
	file->content = (char *)malloc(sizeof(char));
	if (!(file->content))
	{
		free(file);
		return (NULL);
	}
	file->fd = fd;
    file->newline = 0;
    file->eof = 0;
    file->prev = NULL;
	file->next = NULL;
	return (file);
}

static char*   read_allocate(int fd, t_file **file)
{
    char    buf[BUFFER_SIZE + 1];
    char    *ptr;
    ssize_t len;
    ssize_t  idx;

    len = read(fd, buf, BUFFER_SIZE);
    if (len == -1 || len == 0)
    {
        (*file)->eof = 1;
        return (NULL);
    }
    buf[len] = 0x00;
    ptr = ft_strdup(buf);
    if (!ptr)
        return (free_fdfile(file));
    if ((*file)->content)
        free((*file)->content);
    (*file)->content = ptr;
    return (ptr);
}

static char    *parse_fdfile(int fd, t_file **file)
{
    char    *content;
    t_file  *nxt;

    nxt = NULL;
    content = read_allocate(fd, file);
    if (find_newline(content) == -1)
    {
        nxt = t_malloc(fd);
        (*file)->newline = 0;
        (*file)->
    }

    if (!nxt)
        return (NULL);
    nxt->prev = (*file);
    (*file)->next = nxt;
    return (NULL);
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
    ret = parse_fdfile(fd, &file);
	if (!ret)
		return (free_fdfile(&file));
	nxt = file->next;
	free(file);
	flist[fd] = nxt;
	return (file->content);
}
